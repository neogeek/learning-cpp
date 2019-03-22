#ifndef Helpers_h
#define Helpers_h

template<typename T, size_t N>
void printArray(T (&array)[N]) {

    int length = std::size(array);

    std::string output = "";

    for (int i = 0; i < length; i += 1) {

        output += std::to_string(array[i]) + " ";

    }

    std::cout << output << std::endl;

}

template<typename T, size_t N>
void sortArray(T (&array)[N]) {

    int length = std::size(array);

    for (int i = 0; i < length; i += 1) {

        int lowestValueIndex = i;

        for (int j = i; j < length; j += 1) {

            if (array[j] < array[lowestValueIndex]) {

                lowestValueIndex = j;

            }

        }

        std::swap(array[i], array[lowestValueIndex]);

    }

}

#endif
