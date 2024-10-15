#include <stdio.h>

void printBinary(unsigned int num) {
    int bits = sizeof(num) * 8;
    int ceroizquierda = 1;

    for (int i = bits - 1; i >= 0; i--) {
        if ((num >> i) & 1) {
            ceroizquierda = 0;
        }
        if (!ceroizquierda) {
            printf("%d", (num >> i) & 1);
        }
    }
    
    if (ceroizquierda) {
        printf("0");
    }
    
    printf("\n");
}

unsigned int setKthBit(unsigned int num, int k) {
    unsigned int num1 = num;
    return num1 | (1 << k);
}

unsigned int clearKthBit(unsigned int num, int k) {
    unsigned int num1 = num;
    return num1 & ~(1 << k);
}

unsigned int toggleKthBit(unsigned int num, int k) {
    unsigned int num1 = num;
    return num1 ^ (1 << k);
}

unsigned int extractBitField(unsigned int num, int start, int end) {
    unsigned int mask = 0;
    for (int i = start; i <= end; i++) {
        mask |= (1 << i);
    }
    return (num & mask) >> start;
}

unsigned int setBitField(unsigned int num, unsigned int field, int start, int length) {
    unsigned int num1 = num;
    unsigned int mask = (1 << length) - 1;
    num1 &= ~(mask << start);
    return num1 | (field << start);
}

int main() {
    unsigned int num = 103;

    printf("Número original --> Decimal = %u, Binario = ", num);
    printBinary(num);
    unsigned int setResult = setKthBit(num, 3);
    printf("Después de establecer el bit 3 --> Decimal = %u, Binario = ", setResult);
    printBinary(setResult);
    
    printf("\n");
    
    printf("Número original --> Decimal = %u, Binario = ", num);
    printBinary(num);
    unsigned int clearResult = clearKthBit(num, 2);
    printf("Después de limpiar el bit 2 --> Decimal = %u, Binario = ", clearResult);
    printBinary(clearResult);
    
    printf("\n");
    
    printf("Número original --> Decimal = %u, Binario = ", num);
    printBinary(num);
    unsigned int toggleResult = toggleKthBit(num, 1);
    printf("Después de alternar el bit 1 --> Decimal = %u, Binario = ", toggleResult);
    printBinary(toggleResult);
    
    printf("\n");
    
    printf("Número original --> Decimal = %u, Binario = ", num);
    printBinary(num);
    unsigned int extracted = extractBitField(num, 4, 6);
    printf("Campo de bits extraído de 4 a 6 --> Decimal = %u, Binario = ", extracted);
    printBinary(extracted);
    
    printf("\n");
    
    printf("Número original --> Decimal = %u, Binario = ", num);
    printBinary(num);
    unsigned int setFieldResult = setBitField(num, 0b101, 4, 3);
    printf("Después de establecer el campo de bits 101 en la posición 4 --> Decimal = %u, Binario = ", setFieldResult);
    printBinary(setFieldResult);

    return 0;
}
