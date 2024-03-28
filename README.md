# CST321-Memory-Management

This C program demonstrates basic memory management concepts, focusing on virtual memory and address translation using the Memory Management Unit (MMU).

Address Translation with MMU
The program simulates a simple memory management system, where a page table is used to map virtual addresses to physical addresses. The MMU plays a crucial role in this process by translating virtual addresses into real physical addresses. Here's how it works:

1. Virtual Memory and Physical Memory: The system has a virtual memory address space of 1M bytes (0x000FFFFF) and a physical memory address space of 512K bytes (0x7FFFF).

2. Page Table: A page table is used to map virtual pages to physical frames. Each entry in the page table contains a valid bit and a physical frame number.

3. Address Translation: When a virtual address is provided, the MMU consults the page table to find the corresponding physical frame number. It then calculates the physical memory address based on the page size and the physical frame number.

### Separation of Policy and Mechanism
The program separates the policy (page size selection) from the mechanism (address translation). Users can specify the page size (either 4095 or 8191 bytes) to observe how it affects the page table entries and address translation. This separation allows for greater flexibility and adaptability in the memory management system.

### Page Fault Handling
Another important aspect of memory management that is not specifically implemented in this program is fault handling. Page faults occur when a virtual page is not currently mapped to a physical frame in memory.

[![Video](./screenshot/video.png)](https://www.loom.com/share/1ee107a6e6014ba899c9290f6d7d32a1?sid=b9be8c86-0c33-492c-9988-5ee0a4b629c9)
