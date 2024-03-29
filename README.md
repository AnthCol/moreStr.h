# string2.h
### The previous version had memory allocation within the functions. If you would prefer to use that, please review past commits. 
## What is string2.h?
string2.h is a C library that is intended to be an extension of the pre-existing <string.h> library. It includes many string manipulation methods that exist in Java, which are listed below. 

This project formerly required the user to call "free()" after the use of some of these functions. They no longer need to do that, and instead the string passed to the function is the one that gets modified. I feel like it makes more sense to have the user manage all their memory on their own (if they want a copy of the string before sending one to the function they can make it) rather than memory being allocated in a function (these functions, since they take char * as input, will only work if the user has malloc'd a string). 

- substring()
- reverse() [not found in Java]
- isPalindrome() [not found in Java]
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
This was made mainly for fun, but also for convenience when handling C strings. I felt like making a library and the first thing that came to my mind was to make one of the bad parts of C a little bit better. 

## What are the problems and/or limitations of string2.h?
Some functions likely could be written in a faster manner. 
There is also a decent bit of dependency on ctype.h which I would like to get rid of in the future to keep the library as lightweight as possible. 

## What did I learn making string2.h?
Honestly not very much. I wanted to make this library for my own convenience, but I was able to do it with knowledge previously gained in my university classes. Still good practice for string handling though :)


