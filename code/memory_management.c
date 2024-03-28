#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Convert number to binary and return as int array
// Thanks: javapoint.com/return-an-array-in-c
int *toBinary(int input)
{
    // digits will be entered from right to left
    int *binaryResult = (int *)malloc(sizeof(int) * 16); // define size array in memory to return
    int position = 0;

    // extract the digits by dividing by 2 and put the remainder into the array
    while (input != 0)
    {
        binaryResult[position] = input % 2; // should be 1 or 0
        input = input / 2;
        position++;
    }

    return binaryResult;
}

/*
* We calculate the physical frame number by taking the modulus of the virtual page number 
* with the total number of frames. This ensures that the virtual pages are evenly 
* distributed across the available physical frames. 
* Since frames are contiguous blocks of memory, multiplying the physical frame 
* number by the size of each frame gives us the starting address of the physical 
* frame where the virtual page is mapped.
*/
#define VIRTUAL_MEMORY_SIZE 0x000FFFFF // 1M bytes
#define PHYSICAL_MEMORY_SIZE 0x7FFFF // 512K bytes
void populate_page_table(int page_size)
{
    int num_pages = VIRTUAL_MEMORY_SIZE / page_size; // 1M bytes virtual memory size / page_size
    int num_frames = PHYSICAL_MEMORY_SIZE / page_size; // 512K bytes physical memory size/ page size 

    printf("Virtual Page | Physical Frame\n");
    // i represents the virtual page number
    for (int i = 0; i < num_pages; i++)
    {
        printf("%12d | %14d\n", i * page_size, i % num_frames * page_size);
    }
}

int main()
{
    int page_size = 0;

    while (page_size != 4095 && page_size != 8191)
    {
        printf("Enter a page size either 4095 or 8191: \n");
        scanf("%d", &page_size);
    }
    

    printf("\nDisplaying the page size as 16-bit binary number:\n");
    int *binaryInput = toBinary(page_size);
    for (int i = 16; i > 0; i--)
    {
        if (i % 4 == 0 && i != 16) printf(" ");
        printf("%d", binaryInput[i]);
    }
    printf("\n");

    printf("As hexidecimal:\n0x%08X\n", page_size);

    printf("\nPrint the table of for %d-byte page size\n", page_size);
    populate_page_table(page_size);

    printf("\nNow enter a Hexadecimal virtual memory address between 0x00000000 and 0x000FFFFF:\n");
    int virtual_hex_address;
    scanf("%x", &virtual_hex_address);
    printf("\nVirtual memory address: 0x%X\n", virtual_hex_address);
    
    // Calculate physical memory address based on the page size
    // If the address doesn't 
    // int physical_address = virtual_hex_address % (PHYSICAL_MEMORY_SIZE + 1);
    // if (physical_address <= PHYSICAL_MEMORY_SIZE) 
    
    // If the virtual address is less than the physical memory size, they will have 
    // the same address based on this example.  Else if the virtual address is higher
    // than the physical address, print "Currently on disk"
    if (virtual_hex_address <= PHYSICAL_MEMORY_SIZE) 
    {
        printf("Physical memory address: 0x%X\n", virtual_hex_address);
    }
    else
    {
        printf ("Currently on disk\n");
    }   


}