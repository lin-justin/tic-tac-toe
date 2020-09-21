# Tic-Tac-Toe AI Game

My implementation of the Tic-Tac-Toe Game in C++ where the user plays against a simple AI. 

This program was mostly for me to practice using pointers and to get better at C++.

## Usage

This was implemented using [WSL](https://docs.microsoft.com/en-us/windows/wsl/about) with Ubuntu 20.04 and `gcc` version 9.3.0.

```
g++ -o tic-tac-toe tic-tac-toe.cpp
./tic-tac-toe
```

## Takeaways

### References
- A reference is an alias; it's another name for a variable.
- A reference is created using the `&` operator.
- A reference must be initialized when it's defined.
- A reference cannot be changed to refer to a different variable.
- Whatever is done to a reference is done to the variable to which the reference refers.
- When a reference is assigned to a variable, a new copy of the referenced value is created.
- When a variable is passed to a function by value, a copy of the variable to the function is passed.
- When a variable is passed to a function by reference, access to the variable is passed.
- Passing by reference can be more efficient than passing by value, especially when large objects are passed.
- Passing a reference provides direct access to the argument variable passed to a function. As a result, the function can make changes to the argument variable.
- A constant reference cannot be used to change the value to which it refers. A constant reference is declared using the keyword `const`.
- A constant reference or a constant value cannot be assigned to a non-constant reference.
- Passing a constant reference to a function protects the argument variable from being changed by that function.
- Changing the value of an argument variable passed to a function can lead to confusion, consider passing a constant reference before passing a non-constant reference.
- Returning a reference can be more efficient than returning a copy of a value, especially when returning large objects.
- A constant reference to an object can be returned so the object cannot be changed through the returned reference.
- A basic technique of game AI is to have the computer consider all of its legal moves and all of it opponent's legal replies before deciding which move to take next.

### Pointers
- Computer memory is organized in an ordered way, where each chunk of memory has its own unique address.
- A pointer is a variable that contains a memory address.
- In many ways, pointers act like iterators from the STL. For example, just as with iterators, pointers can be used to indirectly access an object.
- To declare a pointer, list a type, followed by an `*`, followed by a name.
- Prefix pointer variables with the letter "p" to be reminded that the variable is a pointer.
- Like an iterator, a pointer is declared to refer to a value of a specific type.
- Initialize a pointer when being declared.
- If a pointer is assigned a 0, it is called a null pointer.
- To get the address of a variable, put the *address of* operator (`&`) before the variable name.
- When a pointer contains the address of an object, it is said to point to the object.
- Unlike references, pointers can be re-assigned. That is, a pointer can point to different objects at different times during the life of a program.
- Just as with iterators, dereferencing a pointer to access the object it points to with `*`, the dereference operator.
- Just as with iterators, the `->` operator can be used with pointers for a more readable way to access object data members and member functions.
- A constant pointer can only point to the object to which it was initialized to point. A constant pointer can be declared by putting the keyword `const` right before the pointer name as in `int* const p = &i;`.
- A pointer to a constant cannot be used to change the value to which it points. A pointer to a constant can be declared by putting the keyword `const` before the type name, as in `const int* p;`.
- A constant pointer to a constant can only point to the value to which it was initialized to a point, and it cannot be used to change that value. A constant pointer to a constant can be declared by putting the keyword `const` before the type name and right before the pointer name, as in `const int* const p = &I;`.
- Pass pointers for efficiency or to provide direct access to an object.
- If a pointer is passed for efficiency, pass a pointer to a constant or a constant pointer to a constant so the object being passed access to cannot be changed through the pointer.
- A dangling pointer is a pointer to an invalud memory address. Dangling pointers are often caused by deleting an object to which a pointer pointed. Dereferencing such a pointer can lead to disastrous results.
- A pointer can be returned from a function but do not return a dangling pointer.
