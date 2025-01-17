Your program includes multiple parts: writing and reading from text files, and working with binary files. Let me go over each section of your code and offer some suggestions for improvement.

1. Writing to a Text File
The section where you're writing user inputs to a text file looks good, but there is a potential issue with the use of scanf("%d %29s", &num, &name). The %29s format specifier limits the size of the name array to 29 characters, but since name is already declared with a size of 30, this works fine. However, you should be cautious about exceeding the array size in more complex scenarios.

Suggested improvement: You should check the return value of scanf to ensure that it successfully reads the expected number of inputs.
2. Reading from a Text File
The code for reading the text file and printing the stored information works well. However, you're using fgetc() to count lines, which is fine but a bit inefficient for large files. Instead, you could read the content line by line.

Suggested improvement: You could count the lines while reading directly without using fgetc()
This way, you can avoid using fgetc() and lineCount.

3. Working with Binary Files
You are writing and reading binary data using the fwrite() and fread() functions. However, there is an issue with how you open the binary file for reading. The binary file is opened for writing ("wb"), but it is never reopened in "rb" mode to read from it after the first write.

Key Improvements:
Error Handling for File Operations: Added more descriptive error messages for file operations.
Input Validation: Ensured the input is valid before processing.
Binary File Read Mode: Fixed the issue with reading from a binary file by reopening it in "rb" mode.
Simplified Reading: Replaced line count logic with a simpler read loop for text files.
This version should work more effectively, handling inputs and file operations in a more reliable manner.
