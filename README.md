# string2.h
### Do not use in memory critical applications (unless you are very diligent)!


## What is string2.h?
string2.h is a C library that is intended to be an extension of the pre-existing <string.h> library. It includes many string manipulation methods that exist in Java, which are listed below. 

Something important to note though, is that many of the methods from Java below create a **new string** and return it. My functions **modify the string that was passed to it**, so make sure to create copies of strings before calling the functions if you need them. 


- substring() [Acts like subSequence() in Java]
- contains() 
- endsWith()
- equalsIgnoreCase()
- indexOf()
- isEmpty() 
- lastIndexOf()
- replaceFirst()
- replace()
- replaceAll()
- startsWith()
- toLowerCase()
- toUpperCase()
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

## What did I learn making string2.h?
Originally, I was going to create this library in a way that would require the user to free memory in main that was allocated within the functions I wrote. 

This has great potential to cause memory leaks, and I would also not have learned anything new about the C language writing the functions this way. 

Instead, I decided to learn about how to manage memory in C in the way that is done in the original <string.h> library so that the user does not need to do anything extra. This involved using pre-existing functions in the string.h library like memset, memcpy etc. **fixme**

