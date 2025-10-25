# FIFO Memory Paging Simulator

A C implementation of the First-In-First-Out (FIFO) page replacement algorithm, demonstrating how operating systems manage memory pages when physical memory is limited.

## Overview

This program simulates the FIFO page replacement algorithm, a simple memory management scheme used by operating systems. When a process requests a page that is not currently in physical memory (a page fault), and all memory frames are full, the FIFO algorithm replaces the oldest page in memory with the requested page.

## How FIFO Works

The FIFO page replacement algorithm works as follows:

1. **Page Queue**: Pages are maintained in memory frames on a first-in-first-out basis
2. **Page Hit**: If a requested page is already in memory, no replacement occurs
3. **Page Fault**: If a requested page is not in memory:
   - If there's an empty frame, the page is loaded into it
   - If all frames are full, the oldest page (first one loaded) is replaced
4. **Replacement**: A circular index tracks which frame to replace next

## Features

- Simulates FIFO page replacement with configurable memory size
- Tracks and displays page faults at each step
- Shows memory state after each page request
- Demonstrates the Belady's anomaly characteristic of FIFO

## Requirements

- GCC compiler (or any C compiler)
- Standard C libraries (`stdio.h`, `stdbool.h`, `stdlib.h`)

## Compilation

To compile the program, use:

```bash
gcc fifoMemoryPaging.c -o fifoMemoryPaging
```

Or with warnings enabled:

```bash
gcc -Wall fifoMemoryPaging.c -o fifoMemoryPaging
```

## Usage

Run the compiled program:

```bash
./fifoMemoryPaging
```

The program uses a predefined page reference string and memory size in the `main()` function.

### Default Configuration

- **Page reference string**: `{0, 1, 2, 3, 4, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 4, 3, 2, 1, 0}`
- **Memory frames**: 3
- **Total pages**: 20

### Example Output

```
FIFO
Faults = 1, inserting 0, memory = 0 -1 -1 
Faults = 2, inserting 1, memory = 0 1 -1 
Faults = 3, inserting 2, memory = 0 1 2 
Faults = 4, inserting 3, memory = 3 1 2 
Faults = 5, inserting 4, memory = 3 4 2 
Faults = 5, inserting 4, memory = 3 4 2 
...
12 page faults.
```

## Code Structure

### Main Function

The `main()` function sets up the page reference string and memory size, then calls the FIFO function.

### FIFO Function

```c
void FIFO(int size, int pages[], int n)
```

**Parameters**:
- `size`: Number of memory frames available
- `pages[]`: Array of page requests (reference string)
- `n`: Total number of page requests

**Process**:
1. Initializes memory frames to -1 (empty)
2. Iterates through each page request
3. Checks if page is already in memory (page hit)
4. If not found (page fault), replaces the oldest page
5. Displays current fault count and memory state
6. Returns total page fault count

## Customization

To test different scenarios, modify the values in `main()`:

```c
// Change the page reference string
int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};

// Change the number of memory frames
int size = 4;
```

## Understanding the Output

- **Faults**: Running count of page faults
- **inserting X**: The page number being requested
- **memory**: Current state of all memory frames (-1 indicates empty frame)

## Educational Purpose

This program is ideal for:
- Understanding page replacement algorithms
- Learning about virtual memory management
- Studying operating system concepts
- Comparing FIFO with other algorithms (LRU, Optimal, etc.)

## Limitations

- Memory frames are statically allocated
- Page reference string is hardcoded
- Only implements FIFO (not LRU, Optimal, or other algorithms)
- No command-line arguments support

## License

This project is available for educational purposes.