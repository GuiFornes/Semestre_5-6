#include <stdio.h>
#include <time.h>
#include <dlfcn.h>

/*int (*calcule)(int,int); // Le pointeur de la fonction en asm
                          
void *load() {
    void *lib= dlopen("./calcule.so",RTLD_LAZY);
    calcule=dlsym(lib,"calcule");
    return lib;
}

void unload(void *lib) {
    dlclose(lib);
}*/

int depile(int P[], int *c){
    int output = P[*c];
    (*c)--;
    return output;
}

void empile(int x, int P[], int *c){
    (*c)++;
    P[*c]=x;
}

int execute(char*s, int a, int b)
{
    int Pile[100];
    int curseur = 0;
    int i = 0;
    int val;
    while (s[i] != 0){
        //printf("%d ---- %d ----- %d\n", s[i], Pile[curseur], curseur);
        switch(s[i]){
            case 42:
                empile(depile(Pile, &curseur)*depile(Pile, &curseur), Pile, &curseur);
                break;
            case 43: 
                val = depile(Pile, &curseur)+depile(Pile, &curseur);
                empile(val, Pile, &curseur);
                break;
            case 44:
                break;
            case 45:
                val = depile(Pile, &curseur) - depile(Pile, &curseur);
                empile((-val), Pile, &curseur);
                break;
            case 97:
                empile(a, Pile, &curseur);
                break;
            case 98:
                empile(b, Pile, &curseur);
                break;
            default:
                val = s[i]-48;
                while (s[++i]!=44){
                    val = 10*val + s[i]-48;                    
                }
                empile(val, Pile, &curseur);
        }
        i++;
    }
    return depile(Pile, &curseur);
}
void compile(char*s)
{
    int i = 0;
    int val;
    FILE *f = fopen("calcule.s", "w");
    fprintf(f, "     section .text\n");
    fprintf(f, "     global calcule\n");
    fprintf(f, "calcule:\n");
    while (s[i] != 0){
        switch(s[i]){
            case 42:
                fprintf(f, "     pop r8\n     pop r9\n     mul r8, r9\n     push r8\n");
                break;
            case 43: 
                fprintf(f, "     pop r8\n     pop r9\n     add r8, r9\n     push r8\n");
                break;
            case 44:
                break;
            case 45:
                fprintf(f, "     pop r8\n     pop r9\n     sub r9, r8\n     push r9\n");
                break;
            case 97:
                fprintf(f, "     push rsi\n");
                break;
            case 98:
                fprintf(f, "     push rdi\n");
                break;
            default:
                fprintf(f, "     mv r10, %d\n", s[i]-48);
                fprintf(f, "     push r10\n");
        }
        i++;
    }
    fprintf(f, "     mv rax, r8\n");
    fprintf(f, "     ret\n");
    fclose(f);
    //system("yasm -felf64 calcule.s");
    //system("gcc -shared -o calcule.so calcule.o -ldl");
}

int calcule(int a, int b);

int main(int argc, char *argv[]) {
    char *calc[100];
    for (int i = 1 ; i < argc ; i++)
        calc[i-1]=argv[i]; 
    int x = execute(*calc, 5, 2);
    printf("x = %d\n", x);
    compile(*calc);
    //void *lib=load();
    //unload(lib);
    return 0;
}


