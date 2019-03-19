#ifndef Vectors_h
#define Vectors_h

struct Vector2 {
    float x;
    float y;
    friend Vector2 operator+(Vector2 a, Vector2 b);
    friend Vector2 operator-(Vector2 a, Vector2 b);
    friend Vector2 operator*(Vector2 a, float b);
    friend Vector2 operator/(Vector2 a, float b);
};

Vector2 operator+(Vector2 a, Vector2 b) {
    return {
        a.x + b.x,
        a.y + b.y
    };
}

Vector2 operator-(Vector2 a, Vector2 b) {
    return {
        a.x - b.x,
        a.y - b.y
    };
}

Vector2 operator*(Vector2 a, float b) {
    return {
        a.x * b,
        a.y * b
    };
}

Vector2 operator/(Vector2 a, float b) {
    return {
        a.x / b,
        a.y / b
    };
}

struct Vector3 {
    float x;
    float y;
    float z;
    friend Vector3 operator+(Vector3 a, Vector3 b);
    friend Vector3 operator-(Vector3 a, Vector3 b);
    friend Vector3 operator*(Vector3 a, float b);
    friend Vector3 operator/(Vector3 a, float b);
};

Vector3 operator+(Vector3 a, Vector3 b) {
    return {
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    };
}

Vector3 operator-(Vector3 a, Vector3 b) {
    return {
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };
}

Vector3 operator*(Vector3 a, float b) {
    return {
        a.x * b,
        a.y * b,
        a.z * b
    };
}

Vector3 operator/(Vector3 a, float b) {
    return {
        a.x / b,
        a.y / b,
        a.z / b
    };
}

const std::string vectorDelimiter = ",";

Vector2 parseVector2FromString(std::string vector) {

    long delimiterIndexFirst = vector.find_first_of(vectorDelimiter);

    return {
        std::stof(vector.substr(0, delimiterIndexFirst)),
        std::stof(vector.substr(delimiterIndexFirst + 1))
    };

}

Vector3 parseVector3FromString(std::string vector) {

    long delimiterIndexFirst = vector.find_first_of(vectorDelimiter);
    long delimiterIndexLast = vector.find_last_of(vectorDelimiter);

    return {
        std::stof(vector.substr(0, delimiterIndexFirst)),
        std::stof(vector.substr(delimiterIndexFirst + 1)),
        std::stof(vector.substr(delimiterIndexLast + 1))
    };

}

#endif /* Vectors_h */
