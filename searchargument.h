#ifndef SEARCHARGUMENT_H
#define SEARCHARGUMENT_H

enum Comparison{moreThan,lessThan,equal,notImportant};

template <class T>
class SearchArgument
{
public:
    T value;
    Comparison comparisonType;
    SearchArgument(T comparableValue, Comparison type);
    bool compare(T comparedValue);
    static Comparison getComparisonFromIndex(int index);
};

template <class T>
Comparison SearchArgument<T>::getComparisonFromIndex(int index)
{
    switch(index)
    {
    case 0: return moreThan;
    case 1: return lessThan;
    case 2: return equal;
    case 3: return notImportant;
    }
    return notImportant;
}

template <class T>
SearchArgument<T>::SearchArgument(T comparableValue, Comparison type)
{
    value = comparableValue;
    comparisonType = type;
}

template <class T>
bool SearchArgument<T>::compare(T comparedValue)
{
    switch(comparisonType)
    {
        case moreThan:
        {
            return (comparedValue > value);
        }
        case lessThan:
        {
            return (comparedValue < value);
        }
        case equal:
        {
            return (comparedValue == value);
        }
        case notImportant:
        {
            return true;
        }
    }
    return false;
}

#endif // SEARCHARGUMENT_H
