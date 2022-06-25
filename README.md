# Ft_Containers

A re-implementation of the `vector`, `stack`, `map` and `set` **C++ containers** from the [**STL**](https://cplusplus.com/reference/stl/). The `stack` implementation is based on the `vector` implementation, and the `set` one on `map`.

The underlying structure of `vector` is a **dynamic array**, and for `map`, it's a **red-black tree**. The code was made to be **modular** and **reusable**: for exemple, the **binary tree** used in `map` can also be used alone.

<br/>

## How to use these containers

Copy the wanted containers header files, and also `utils`, `iterator`, `binary_tree` (for **map** and **set**) directories into your project. Then, just include the container in your code.

_myFile.cpp_

```cpp
#include "[path_to_the_copied_container]/vector.hpp"
```

<br/>

## Unit testing

To really understand how the STL containers worked, and to be sure that my implementation was behaving correctly, I creating a unit testing tool called [**Cavalry**](https://github.com/Ourobore/Cavalry). You can find more informations about it on it's [repository](https://github.com/Ourobore/Cavalry).

<br/>

## Notes

`.devcontainer`, `.vscode`, `.clang-format` and `compile_flags.txt` where files/directories needed to facilitate development. They where used to: have a common dev environment, launch debugger, and use **lldb** and **clang format**.
