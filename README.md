Dynamic Loading Example
=======================

I've recently become interested in how dynamic loading of shared objects works in c++ and other languages.
Dynamic loading has found it's main use as a basis for plugin systems for applications like notepad++ for example, which
loads plugins from dll files in a certain directory in it's folder structure.

## How does it work?

Dynamic library loading works similarly to how linking against a shared library does (at least to my knowledge of these concepts).
A library must first be loaded from the file system, and then you can search for certain symbols within
this library that correspond to functions, or variables, etc.

## Examples

Here's a small example in c++:

An example library that we can import functions from at runtime:

```cpp
// file: greetings.cpp

#include <iostream>

extern "C" {
    void say_hello() {
        std::cout << "Hello world?\n";
    }
    
    void say_good_evening() {
        std::cout << "konbanwa!\n";
    }
}
```

The main point to take from the code above is the `extern "C"` wrapping the functions that we want to expose.
This is because the tools that we're going to use later on require the C naming conventions, and since c++ does some
interesting things with it's name mangling, we're required to export these functions using the C naming convention. 

A side effect of this is that we can't have overloaded functions in our `extern` block, since the exported symbol names
would be the same and would therefore clash.

Next up we have the program that will load this shared object at runtime:

```cpp
// file: main.cpp

#include <dlfcn.h>
#include <iostream>

// A function pointer
using Func = void*(*)(void);

int main(void) {
    void* handle = dlopen("libgreetings.so", RTLD_LAZY);
    if(!handle) {
        std::cerr << dlerror() << std::endl;
        return 1;
    }
    
    void* func = (Func)dlsym(handle, "say_hello");
    func();
    
    return 0;
}
```

There's a few things going on here, so let's explain:

```cpp
#include <dlfcn.h>
```

The `dlfcn.h` header defines all of the functions required to interact with dynamically loaded functions.
This is where the `dlopen`, `dlerror`, and `dlsym` functions seen later on in the example come from.

```cpp
void* handle = dlopen("libgreetings.so", RTLD_LAZY)
```

`dlopen` opens a shared object file, which in this case is `libname.so`. The `RTLD_LAZY` macro defines how
eager we are to load the symbols in the object. In this case we're going to load them lazily, i.e, only when
we need them. Notice that dlopen returns a `void*`, in this case, this just means that `handle` is a pointer into the 
shared object. This `handle` is what we're going to use to interact with the symbols in this library.

```cpp
using Func = void*(*)(void);

...

Func func = (Func)dlsym(handle, "say_hello");
func();
```

Here we see another useful function from the `dlfcn.h` header, `dlsym`. This function allows us to acquire a pointer
to a symbol inside of the shared object. In our case, we're trying to grab a function named `say_hello`. However, because this
function returns a `void*`, we can't actually call it like a function. Thus the function pointer (Func) `using` declaration
above. This allows us to cast the returned pointer to a callable function type, which we use on the next line.


And then a makefile to round it all out:

```make
# file: Makefile

all: main libgreetings.so

main: main.cpp
    g++ main.cpp -o main
    
libgreetings.so: greetings.cpp
    # -fpic Position Independent Code -> for the compilation step
    # -shared Create a shared object -> for the linking step
    g++ -fpic -shared greetings.cpp -o libgreetings.so
```