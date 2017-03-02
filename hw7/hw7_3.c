#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union U{
	int n;
	float f;
	char s[32];
    struct{unsigned char b0:1, b1:1, b2:1, b3:1,b4:1, b5:1, b6:1, b7:1,
			 b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, b15:1,
			 b16:1, b17:1, b18:1, b19:1, b20:1, b21:1, b22:1, b23:1,
			 b24:1, b25:1, b26:1, b27:1, b28:1, b29:1, b30:1, b31:1;};
};
void print_binary(union U var)
{
    printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",
        var.b31,var.b30,var.b29,var.b28,
        var.b27,var.b26,var.b25,var.b24,
        var.b23,var.b22,var.b21,var.b20,
        var.b19,var.b18,var.b17,var.b16,
        var.b15,var.b14,var.b13,var.b12,
        var.b11,var.b10,var.b9,var.b8,
        var.b7,var.b6,var.b5,var.b4,
        var.b3,var.b2,var.b1,var.b0);
}
int main(int argc, char* argv[])
{    
	int type;
	type = atoi(argv[1]);

        union U var;

	if(type == 1){
	var.n = atoi(argv[2]);
	print_binary(var);
	}

	if(type == 2){
	var.f = atof(argv[2]);
        print_binary(var);
	}

	if(type == 3){
	strcpy(var.s,argv[2]);
	if(var.s[0] == '0') var.b31 = !var.b31;
        if(var.s[1] == '0') var.b30 = !var.b30;
        if(var.s[2] == '0') var.b29 = !var.b29;
        if(var.s[3] == '0') var.b28 = !var.b28;
        if(var.s[4] == '0') var.b27 = !var.b27;
        if(var.s[5] == '0') var.b26 = !var.b26;
        if(var.s[6] == '0') var.b25 = !var.b25;
        if(var.s[7] == '0') var.b24 = !var.b24;
        if(var.s[8] == '0') var.b23 = !var.b23;
        if(var.s[9] == '0') var.b22 = !var.b22;
        if(var.s[10] == '0') var.b21 = !var.b21;
        if(var.s[11] == '0') var.b20 = !var.b20;
        if(var.s[12] == '0') var.b19 = !var.b19;
        if(var.s[13] == '0') var.b18 = !var.b18;
        if(var.s[14] == '0') var.b17 = !var.b17;
        if(var.s[15] == '0') var.b16 = !var.b16;
        if(var.s[16] == '0') var.b15 = !var.b15;
        if(var.s[17] == '0') var.b14 = !var.b14;
        if(var.s[18] == '0') var.b13 = !var.b13;
        if(var.s[19] == '0') var.b12 = !var.b12;
        if(var.s[20] == '0') var.b11 = !var.b11;
        if(var.s[21] == '0') var.b10 = !var.b10;
        if(var.s[22] == '0') var.b9 = !var.b9;
        if(var.s[23] == '0') var.b8 = !var.b8;
        if(var.s[24] == '0') var.b7 = !var.b7;
        if(var.s[25] == '0') var.b6 = !var.b6;
        if(var.s[26] == '0') var.b5 = !var.b5;
        if(var.s[27] == '0') var.b4 = !var.b4;
        if(var.s[28] == '0') var.b3 = !var.b3;
        if(var.s[29] == '0') var.b2 = !var.b2;
        if(var.s[30] == '0') var.b1 = !var.b1;
        if(var.s[31] == '0') var.b0 = !var.b0;
	printf("%.23e \n",var.f);
	}
	return 0;
}
