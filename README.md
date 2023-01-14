# Dynamic Array C
A C program that allows you to create a simple list of songs. It requires the use of specific data structures and the correct implementation of specific methods. The user of the program must be able to do this

● Add a song to the list by specifying its name and length

● Delete a song from the list by name

●List up all songs

Implementations must satisfy the following constraints

● To store songs, you must use the dynamic_array data structure. The initial capacity of dynamic_array must be 2, and 2 void* must be allocated on the heap by using malloc() to allocate NULL values. The element pointer must store the address returned by malloc(). Implement these operations in the init_array function.

● If the user adds a new song, it should be created on the heap using malloc(). We need to insert the address of this song into the song using the put_element function. The put_element function should increase the size of the element array and put the address of the newly added element into the element array. Place it in the first available position. ● If the user wants to delete a song, it should be found with the get_element function and removed from the heap using the free() function. Use remove_element to remove that address from the song.

● Whenever the size of dynamic_array reaches its capacity, the capacity must be doubled from the old one and the elements of the elemental array must be copied to the newly allocated elemental array. Elements of the Elements array that do not yet refer to a valid song should be assigned a NULL value. All these operations should be implemented in the put_element function. ● Every time the size of dynamic_array decreases by its capacity/2, it reduces its capacity by a factor of 2, allocates space for that capacity, copies the values of the array elements to the newly allocated array elements, and replaces the old array allocation. Release. An element with a free( on. ) function. All these operations should be implemented in the remove_element function.

● When listing songs, you must use the get_element function to get the song address at that position. Note that get_element returns void* so you can cast the type from void* to song* and then access the song field. remarks:


● The elements field of dynamic_array is a pointer that stores the addresses of the elements, not the elements. You can think of the elements as an array of void*.

● The heap above is a memory area, not a data structure. You can use the dynamic memory allocation functions (malloc(), free(), etc.) declared in stdlib.h to create or manipulate objects on the heap.

● NULL is also declared in stdlib.h. Used as an address pointing to 0. This means that either there is no valid data at this address or no data has been assigned yet. NULL can be used to indicate that the pointer has not yet been initialized, or that the value it points to has been freed.
