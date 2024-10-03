class newString
{
    private:
        char* str;
        size_t len;
        size_t currentCapacity;


        //Own String functions
        size_t getLength(const char* input); //get Length
        void copyString(char*  thisString, const char* source);

    public:
        //Rule of Five
        //newString();
        newString(const char* initStr = ""); //Constructor

        ~newString(); //Destructor
        newString(const newString& other); //Copy Constructor
        newString& operator=(const newString& other); //Copy AssignmentOperator
        newString(newString&& other) noexcept; //Move Constructor
        newString& operator=(newString&& other) noexcept; //Move Assignment Operator

        //Exercise specific
        void append(const char* stringToAppend);
        const char* c_str() const;
        size_t length() const;
        size_t size() const;

        //Bonus
        void reserve(size_t newCapacity);
        size_t capacity() const;

        
};