#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dynamic_array {
    int capacity;
    int size;
    void **elements;
} dynamic_array;


void init_array(dynamic_array *array) {
    array->capacity = 2;
    array->size = 0;
    array->elements = (void **) malloc(sizeof(void *) * 2);

    for (int i = 0; i < array->capacity; i++) {
        array->elements[i] = NULL;
    }
}

void *get_element(dynamic_array *array, int position) {
    return array->elements[position];
}

void put_element(dynamic_array *array, void *element) {
    array->size++;
    if (array->size == array->capacity) {
        // create a new array which has double capacity
        void **new_elements = (void **) malloc(sizeof(void *) * array->capacity * 2);

        // copy all elements from old array to new array
        int index = 0;
        for (int i = 0; i < array->capacity; i++) {
            if (array->elements[i] != NULL) {
                new_elements[index] = array->elements[i];
                index++;
            }
        }

        // assign NULL to unused elements
        for (int i = 0; i < ((array->capacity * 2) - index); i++) {
            new_elements[index + i] = NULL;
        }

        // free old array
        free(array->elements);

        // assign new array to old array
        array->elements = new_elements;
        array->capacity *= 2;
    }

    // put the element to correct position
    for (int i = 0; i < array->capacity; i++) {
        if (array->elements[i] == NULL) {
            array->elements[i] = element;
            break;
        }
    }
}

void remove_element(dynamic_array *array, int position) {
    // if the position is out of range, do nothing
    if (position < 0 || position >= array->capacity) {
        printf("Invalid position\n");
        return;
    }

    array->size--;
    void *element = get_element(array, position);

    // free the element and assign NULL to the position
    free(element);
    array->elements[position] = NULL;

    // if the size is less than or equal 1/2 of capacity, create a new array which has half capacity
    // But don't do this if the capacity is 2 (minimum capacity)
    if (array->capacity <= 2) {
        return;
    } else if (array->size < array->capacity / 2) {
        void **new_elements = (void **) malloc(sizeof(void *) * array->capacity / 2);

        // copy all elements from old array to new array
        int index = 0;
        for (int i = 0; i < array->capacity; i++) {
            if (array->elements[i] != NULL) {
                new_elements[index] = array->elements[i];
                index++;
            }
        }

        // assign NULL to unused elements
        for (int i = 0; i < ((array->capacity / 2) - index); i++) {
            new_elements[index + i] = NULL;
        }

        // free old array
        free(array->elements);
        // assign new array to old array
        array->elements = new_elements;
        array->capacity /= 2;
    } else {
        void **new_elements = (void **) malloc(sizeof(void *) * array->capacity);

        // copy all elements from old array to new array
        int index = 0;
        for (int i = 0; i < array->capacity; i++) {
            if (array->elements[i] != NULL) {
                new_elements[index] = array->elements[i];
                index++;
            }
        }

        // assign NULL to unused elements
        for (int i = 0; i < ((array->capacity) - index); i++) {
            new_elements[index + i] = NULL;
        }

        // free old array
        free(array->elements);
        // assign new array to old array
        array->elements = new_elements;
    }
}

typedef struct song {
    char *name;
    float duration;
} song;

// delete a song from the list by providing its name
void remove_element_by_name(dynamic_array *array, char *name) {
    for (int i = 0; i < array->capacity; i++) {
        if (get_element(array,i) != NULL) {
            song *s = (song *) get_element(array, i);

            // if elements name and given name are same, remove the element
            if (strcmp((char *) s->name, name) == 0) {
                remove_element(array, i);
                return;
            }
        }
    }
    printf("No song with name %s\n", name);
}

// list all songs
void list_all_songs(dynamic_array *array) {
    for (int i = 0; i < array->capacity; i++) {
        if (get_element(array,i) != NULL) {
            song *s = (song *) get_element(array, i);
            printf("\nSong name: %s  Duration: %f index: %d\n", s->name, s->duration, i);
        } else {
            // if you want to print the index and itself of NULL elements, uncomment the following line
            // printf("NULL\n");
        }
    }
}

//  add a song to the list by providing its name and duration
void put_element_by_name_and_duration(dynamic_array *array, char *name, float duration) {
    song *s = malloc(sizeof(void *));
    s->name = name;
    s->duration = duration;
    put_element(array, s);
}

int main() {
    // initialize the dynamic array
    dynamic_array array;
    init_array(&array);

    while (1) {
        printf("\n*********MENU*********\n");
        printf("1)List all songs\n");
        printf("2)Add a song\n");
        printf("3)Delete a song\n");
        printf("4)Exit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            fflush(stdin);
            list_all_songs(&array);

        } else if (choice == 2) {
            char* name = malloc(sizeof(void *));
            float duration;

            fflush(stdin);
            printf("Enter name:");
            scanf("%[^\n]s", name);

            fflush(stdin);
            printf("Enter duration:");
            scanf("%f", &duration);
            put_element_by_name_and_duration(&array, name, duration);

        } else if (choice == 3) {
            char* name = malloc(sizeof(void *));

            fflush(stdin);
            printf("Enter name: ");
            scanf("%[^\n]s", name);

            remove_element_by_name(&array, name);

        } else if (choice == 4) {
            break;

        } else {
            printf("Invalid choice\n");
        }
    }

    free(array.elements);
    return 0;
}