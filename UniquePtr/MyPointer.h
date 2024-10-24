#ifndef MYPOINTER_H
#define MYPOINTER_H

template<typename T, typename Deleter = void(*)(T*)>
class MyPointer {
public:
    MyPointer(T* ptr = nullptr);  // Konstruktor mit optionalem Pointer
    MyPointer(T* ptr, Deleter deleter);  // Konstruktor mit Pointer und benutzerdefiniertem Deleter
    ~MyPointer();  // Destruktor

    MyPointer(MyPointer&& other) noexcept;  // Move-Konstruktor
    MyPointer& operator=(MyPointer&& other) noexcept;  // Move-Zuweisungsoperator

    MyPointer(const MyPointer& other) = delete;  // Kopierkonstruktor gelöscht
    MyPointer& operator=(const MyPointer& other) = delete;  // Zuweisungsoperator gelöscht

    T& operator*() const;  // Dereferenzierungsoperator
    T* operator->() const;  // Pfeiloperator
    explicit operator bool() const;  // Boolesche Umwandlung

    T* release();  // release methode
    void reset(T* newPtr = nullptr);  // Pointer zurücksetzen mit neuem Pointer oder nullptr
    void swap(MyPointer& other);  // Pointer mit einem anderen MyPointer tauschen

private:
    T* ptr;  // Der Pointer auf das verwaltete Objekt
    Deleter deleter;  // Der benutzerdefinierte oder Standard-Deleter

    // Standard-Deleter Funktion, um Speicher freizugeben
    static inline void DefaultDeleter(T* ptr) {
        delete ptr;
    }
};

//Implementierungen weil es bei Templates bereits im Header implementiert werden muss

// Konstruktor mit optionalem Pointer
template<typename T, typename Deleter>
MyPointer<T, Deleter>::MyPointer(T* ptr) : ptr(ptr), deleter(DefaultDeleter) {}

// Konstruktor mit benutzerdefiniertem Deleter
template<typename T, typename Deleter>
MyPointer<T, Deleter>::MyPointer(T* ptr, Deleter deleter) : ptr(ptr), deleter(deleter) {}

// Destruktor
template<typename T, typename Deleter>
MyPointer<T, Deleter>::~MyPointer() {
    if (ptr) {
        deleter(ptr);  // Verwaltetem Pointer wird Speicher freigegeben
    }
}

// Move-Konstruktor
template<typename T, typename Deleter>
MyPointer<T, Deleter>::MyPointer(MyPointer&& other) noexcept : ptr(other.ptr), deleter(other.deleter) {
    other.ptr = nullptr;  // Übertragung des Eigentums, alter Pointer wird null
}

// Move-Zuweisungsoperator
template<typename T, typename Deleter>
MyPointer<T, Deleter>& MyPointer<T, Deleter>::operator=(MyPointer&& other) noexcept {
    if (this != &other) {  // Selbstzuweisung prüfen
        reset();  // Aktuelles Objekt zurücksetzen
        ptr = other.ptr;
        deleter = other.deleter;
        other.ptr = nullptr;
    }
    return *this;
}

// Dereferenzierungsoperator (*)
template<typename T, typename Deleter>
T& MyPointer<T, Deleter>::operator*() const {
    return *ptr;
}

// Pfeiloperator (->)
template<typename T, typename Deleter>
T* MyPointer<T, Deleter>::operator->() const {
    return ptr;
}

// Boolesche Umwandlung
template<typename T, typename Deleter>
MyPointer<T, Deleter>::operator bool() const {
    return ptr != nullptr;
}

// Freigabe des Pointers
template<typename T, typename Deleter>
T* MyPointer<T, Deleter>::release() {
    T* oldPtr = ptr;
    ptr = nullptr;
    return oldPtr;  // Gibt den raw Pointer zurück und setzt internen Pointer auf nullptr
}

// Zurücksetzen des Pointers mit Standardwert nullptr
template<typename T, typename Deleter>
void MyPointer<T, Deleter>::reset(T* newPtr) {
    if (ptr) {
        deleter(ptr);  // Aktuelles Objekt wird gelöscht
    }
    ptr = newPtr;  // Neuer Pointer wird gesetzt
}

// Tauschen der Pointer und Deleter zwischen zwei MyPointer Objekten
template<typename T, typename Deleter>
void MyPointer<T, Deleter>::swap(MyPointer& other) {
    T* tempPtr = this->ptr; //Temporärer irgendwas Pointer wird dem ptr wert des jetztigen MyPointer Objekts gesetzt
    this->ptr = other.ptr; //Der ptr wert des jetztigen MyPointer Objekts wird auf den ptr Wert des übergebenen (other) MyPointer Objects gesetzt
    other.ptr = tempPtr; //der ptr wert des übergebenen Objekts (other) wird auf den wert von dem jetzigen Objekt gesetzt

    // Gleich mit dem Custom Deleter
    Deleter tempDeleter = this->deleter;
    this->deleter = other.deleter;
    other.deleter = tempDeleter;

}

#endif // MYPOINTER_H
