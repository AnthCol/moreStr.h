# string2.h
### Do not use in memory critical applications (unless you are very diligent)!


## What is string2.h?
string2.h is a C library that is intended to be an extension of the pre-existing <string.h> library. 
It includes many string manipulation functions that exist in Java, such as:
- substring()  **requires free**
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
- subsequence() [maybe]

Most of the functions run in O(n) (linear) time. 
## Why did I make string2.h?
This was made mainly for fun. I felt like making a library and the first thing that came to my mind was to make one of the bad parts of C a little bit better. 
Granted, this library definitely has its flaws since you need to free your memory manually in main after using some of the functions from this library. 
Other than that, it works well. 

## What did I learn making string2.h?
I learned that the original <string.h> library has some crazy memory management stuff going on so that the user does not have to call free() in main. Super impressive that people made that and very interesting. 

Outside of that, honestly not much. I got good practice working with strings in C, but I was able to make everything here with knowledge that I gained from my university classes. 
