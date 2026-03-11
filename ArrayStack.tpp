template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    // TODO
    maxSize = i;                // sets max number of elements in stack
    buffer = new T[maxSize];    // dynamikcilay allocates the array for stack 
    this->length = 0;           // length to 0 or empty
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    // TODO
    delete[] buffer;        // delete array memory
    buffer = nullptr;       // make buffer null
    this->length = 0;       // make stack empty size wise
    maxSize = 0;            // reset capacity
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;              // copy maxe size
    this->length = copyObj.length;          // copy length
    buffer = new T[maxSize];                // crerate new array and dynamically
    for (int i = 0; i < this->length; i++){ // copy it all
        buffer[i]  = copyObj.buffer[i];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    // TODO
    if (isEmpty()){                         // check if empty and if so throw error
        throw string("Stack is empty");
    }
    return buffer[this->length - 1];                    // if not empty return the length  - 1 of the buffer
}

template <typename T>
void ArrayStack<T>::pop() {
    // TODO
        if (isEmpty()){                         // check if empty and if so throw error
        throw string("Stack is empty");
    }
    this->length--;                             // just reduce the length and it takes away the top
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // TODO
    if (isFull()){                         // check stack and throw if so
        throw string("Stack is full");
    }
    buffer [this->length] = elem;          // place new elememnt as the new open spot
    this->length++;     // change length
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO
    if (this->length <= 1) return;   // if the length is less than 1 or 1 then you cont do abnything

    if (dir == Stack<T>::RIGHT) {       // if right
        T temp = buffer[this->length - 1];   // save top element
        for (int i = this->length - 1; i > 0; i--) { // shift elements right
            buffer[i] = buffer[i - 1];
        }
        buffer[0] = temp;                    // move old top to bottom
    }
    else {
        T temp = buffer[0];                  // save bottom element
        for (int i = 0; i < this->length - 1; i++) {       // shift elements left
            buffer[i] = buffer[i + 1];
        }
        buffer[this->length - 1] = temp;     // move old bottom to top
    }
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}
