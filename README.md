# string2.h
### Do not use in memory critical applications (unless you are very diligent)!


## What is string2.h?
string2.h is a C library that is intended to be an extension of the pre-existing <string.h> library. It includes many string manipulation methods that exist in Java, which are listed below. 

The functions below that say "requires free" do the same thing that some of the string methods in Java do (creates a new string and returns it). For this reason, you have to free the memory in your main function to avoid leaks (see limitations section for more). 

- substring() **requires free**
- contains() 
- endsWith()
- equalsIgnoreCase()
- indexOf()
- isEmpty() 
- lastIndexOf()
- startsWith()
- trim()
- regionMatches()
- valueOfInt()
    - Java has valueOf where you can do any number. This one will only be for integers
    - I might add for double/float/long/unsigned/etc. In the future. 

Most of the functions run in O(n) (linear) time. 

## Why did I make string2.h?
This was made mainly for fun. I felt like making a library and the first thing that came to my mind was to make one of the bad parts of C a little bit better. 
Granted, this library definitely has its flaws since unlike Java, it does not create a new string and return that when you call the function/method. It will modify the string that is sent to it. I originally used malloc within the functions, but it would require the user to free the memory created in the function which could get messy. Instead, all of the memory management will be done in main by the user of the library, and the functions will only modify the strings sent the function and return them. 
Other than that, it works well. 

## What are the problems and/or limiations of string2.h?
The main issue I have with this library is that it requires the user to call free in main and keep track of memory that was allocated in the function. When you don't do the memory allocation by hand it can be an easy thing to forget about, so I really don't like that it is set up that way. 
I would like to learn more about memory management in C to see if it is even possible to modify strings the way I want to. I have already done a little bit of research into it and with what I was seeing it made me feel as though I would have to settle with this solution for now. Maybe I will come across something in the future that will allow me to modify the values of the string that was passed to the function and then send it back to main. 

// NEEDS TO BE TESTED: It has been run in Valgrind, and as long as the memory is freed in main. There are no memory leaks as a result of the functions I wrote. 

## What did I learn making string2.h?
Originally, I was going to create this library in a way that would require the user to free memory in main that was allocated within the functions I wrote. 

This has great potential to cause memory leaks, and I would also not have learned anything new about the C language writing the functions this way. 

Instead, I decided to learn about how to manage memory in C in the way that is done in the original <string.h> library so that the user does not need to do anything extra. This involved using pre-existing functions in the string.h library like memset, memcpy etc. **fixme**

