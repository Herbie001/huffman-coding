# Command Line Interface

The command-line interface is at the heart of this program. I wanted to originally just implement a single file compression or decompression; however, I thought about implementing multithreading if the user chose to compress multiple files (a maximum of 3) at one time. 

# Commands

Used commandArgumentProcessor just incase the user types the correct key word but capitalizes it in an odd way, just to make the program operation in the face of an oddly typed request that is technically correct.

## File Compression & Decompression

For file compression, I wanted to make it simple for the user to implement 


### Varify File Compression 

In order to varify lossless data compression, two example files are included along with two corresponding compressed files. It's recommended to do this because then we can varify the compression or decompression was a success. Additionally, its important to view the ratio of compression and inspect this level of compression with more renowned compression algorithms that come with particular OS such as, windows, and iOS.

Compare compressed .bin file with the original .txt file.
``` bash
    diff compressed-file-example.bin example-txt-file.txt
```

Compare compressed .bin file with the original .bin file. 
``` bash
    diff compressed-file-example.bin example-bin-file.bin
```


### Benchmarking With Renowned File Compression

Compare with compressed file using windows 11 compression software or any other software readily available.
``` bash
    diff compressed-file-example.huff compressed-file-example
```

See compression statistics by using the following bash command.
```bash
    statistics compressed-file-example.txt compressed-file-example.huff
```


# Developer Thoughts

For the CLI, I want to make it as fool proof as possible to cover all the edge and corner cases like entering empty spaces, nonstrings, empty files, adding extra spaces even after a valid number is entered, etc. Used 


# References

[cin & getline()](https://www.geeksforgeeks.org/cpp/problem-with-getline-after-cin/)

[out_of_range exception](https://cplusplus.com/reference/stdexcept/out_of_range/)
