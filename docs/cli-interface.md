// TODO 
# Command Line Interface

This CLI will implement a plethora of commands analogous to a command in linux.  

# Commands



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


Compare with compressed file using windows 11 compression software
``` bash
    diff 
```



