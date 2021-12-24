
int mx_strlen(const char *s);

int mx_insertion_sort(char **arr, int size) {
    int location;
    char *newElement;
    int counter = 0;
    for (int i = 1; i < size; i++) {
        newElement = arr[i];
        location = i - 1;
        while (location >= 0 && mx_strlen(arr[location]) > mx_strlen(newElement)) {
            arr[location + 1] = arr[location];
            location = location - 1;
            counter++;
        }
        arr[location + 1] = newElement;
    }
    return counter;
}

