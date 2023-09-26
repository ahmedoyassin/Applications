#define SET_BIT(var,bit)  ( var = var | 1<<(bit) ) // OR with 1
#define CLR_BIT(var,bit)  ( var = var & ~(1<<(bit)) ) // AND with 0
#define GET_BIT(var,bit)  ( (var>>bit) & 1 ) // AND with 1 
#define TOGGLE_BIT(var,bit) ( var = var ^(1<<bit) ) // XOR with 1 