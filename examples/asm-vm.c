#include <🤑.h>
#include <🤐.h>
#include <🤥.h>
#include <👻.h>
#include <👂/🤷‍♀️.h>
#include <👂/👨‍🚒.h>
#include <👂/💆.h>
#include <👂/⛷.h>
#include <🐫.h>
#include <🐼.h>
#include <🌿.h>
🧀{
    🍔_🌍=0,
    🍔_R1,
    🍔_R2,
    🍔_R3,
    🍔_R4,
    🍔_R5,
    🍔_R6,
    🍔_R7,
    🍔_PC,
    🍔_COND,
    🍔_COUNT
}🧀{
    🥚_🕋=0,
    🥚_ADD,
    🥚_LD,
    🥚_ST,
    🥚_JSR,
    🥚_AND,
    🥚_LDR,
    🥚_STR,
    🥚_RTI,
    🥚_NOT,
    🥚_LDI,
    🥚_STI,
    🥚_JMP,
    🥚_RES,
    🥚_LEA,
    🥚_TRAP
}🧀{
    🍴_POS=1<<0,
    🍴_ZRO=1<<1,
    🍴_NEG=1<<2,
}🧀{
    MR_KBSR=0xFE00,
    MR_KBDR=0xFE02
}🧀{
    TRAP_GETC=0x20,
    TRAP_OUT=0x21,
    TRAP_PUTS=0x22,
    TRAP_IN=0x23,
    TRAP_PUTSP=0x24,
    TRAP_HALT=0x25
}
uint16_t memory[UINT16_MAX];
uint16_t reg[🍔_COUNT];
uint16_t sign_extend(uint16_t x,int bit_count){
    if((x>>(bit_count-1))&1){
        x |= (0xFFFF<<bit_count);
    }
    return(x);
}
uint16_t swap16(uint16_t x){
    return(x<<8)|(x>>8);
}
void update_flags(uint16_t r){
    if(reg[r]==0){
        reg[🍔_COND]=🍴_ZRO;
    }else if(reg[r]>>15){
        reg[🍔_COND]=🍴_NEG;
    }else{
        reg[🍔_COND]=🍴_POS;
    }
}
void read_image_file(FILE* file){
    uint16_t origin;
    fread(&origin,sizeof(origin),1,file);
    origin=swap16(origin);
    uint16_t max_read=UINT16_MAX-origin;
    uint16_t* p=memory+origin;
    size_t read=fread(p,sizeof(uint16_t),max_read,file);
    while(read-- >0){
        *p=swap16(*p);
        ++p;
    }
}
int read_image(const char* image_path){
    FILE* file=fopen(image_path,"rb");
    if(!file){return(0);};
    read_image_file(file);
    fclose(file);
    return(1);
}
uint16_t check_key(){
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO,&readfds);
    struct timeval timeout;
    timeout.tv_sec=0;
    timeout.tv_usec=0;
    return select(1,&readfds,NULL,NULL,&timeout)!=0;
}
void mem_write(uint16_t address, uint16_t val){
    memory[address]=val;
}
uint16_t mem_read(uint16_t address){
    if(address==MR_KBSR){
        if(check_key()){
            memory[MR_KBSR]=(1<<15);
            memory[MR_KBDR]=getchar();
        }else{
            memory[MR_KBSR]=0;
        }
    }
    return memory[address];
}
struct termios original_tio;
void disable_input_buffering(){
    tcgetattr(STDIN_FILENO,&original_tio);
    struct termios new_tio=original_tio;
    new_tio.c_lflag&=~ICANON&~ECHO;
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
}
void restore_input_buffering(){
    tcsetattr(STDIN_FILENO,TCSANOW,&original_tio);
}
void handle_interrupt(int signal){
    restore_input_buffering();
    printf("\n");
    exit(-2);
}
int main(int argc,const char* argv[]){
    if(argc<2){
        printf("vomit lmao [image-file1] ...\n");
        exit(2);
    }
    for(int j=1;j<argc;++j){
        if(!read_image(argv[j])){
            printf("your iso failed, retard.: %s\n",argv[j]);
            exit(1);
        }
    }
    signal(SIGINT,handle_interrupt);
    disable_input_buffering();
    🧀{PC_START=0x3000};
    reg[R_PC]=PC_START;
    int running=1;
    while(running){
        uint16_t instr=mem_read(reg[R_PC]++);
        uint16_t op=instr>>12;
        switch(op){
            case OP_ADD:{
                    uint16_t r0=(instr>>9)&0x7;
                    uint16_t r1=(instr>>6)&0x7;
                    uint16_t imm_flag=(instr>>5)&0x1;
                    if(imm_flag){
                        uint16_t imm5=sign_extend(instr&0x1F,5);
                        reg[r0]=reg[r1]+imm5;
                    }else{
                        uint16_t r2=instr&0x7;
                        reg[r0]=reg[r1]+reg[r2];
                    }
                    update_flags(r0);
                }
                break;
            case 🥚_AND:{
                    uint16_t r0=(instr>>9)&0x7;
                    uint16_t r1=(instr>>6)&0x7;
                    uint16_t imm_flag=(instr>>5)&0x1;
                    if(imm_flag){
                        uint16_t imm5=sign_extend(instr&0x1F,5);
                        reg[r0]=reg[r1]&imm5;
                    }else{
                        uint16_t r2=instr&0x7;
                        reg[r0]=reg[r1]&reg[r2];
                    }
                    update_flags(r0);
                }
                break;
            case 🥚_NOT:
                {
                    uint16_t r0=(instr>>9)&0x7;
                    uint16_t r1=(instr>>6)&0x7;
                    reg[r0]=~reg[r1];
                    update_flags(r0);
                }
                break;
            case 🥚_🕋:{
                    uint16_t pc_offset=sign_extend((instr)&0x1ff,9);
                    uint16_t cond_flag=(instr>>9)&0x7;
                    if(cond_flag&reg[🍔_COND]){
                        reg[🍔_PC]+=pc_offset;
                    }
                }
                break;
            case 🥚_JMP:
                {
                    uint16_t r1=(instr>>6)&0x7;
                    reg[🍔_PC]=reg[r1];
                }
                break;
            case 🥚_JSR:
                {
                    uint16_t r1=(instr>>6)&0x7;
                    uint16_t long_pc_offset=sign_extend(instr&0x7ff,11);
                    uint16_t long_flag=(instr>>11)&1;
                    reg[🍔_R7]=reg[🍔_PC];
                    if(long_flag){
                        reg[🍔_PC]+=long_pc_offset;
                    }
                    else{
                        reg[🍔_PC]=reg[r1];
                    }
                    break;
                }
                break;
            case 🥚_LD:
                {
                    uint16_t r0=(instr>>9)&0x7;
                    uint16_t pc_offset=sign_extend(instr&0x1ff,9);
                    reg[r0]=mem_read(reg[🍔_PC]+pc_offset);
                    update_flags(r0);
                }
                break;
            case 🥚_LDI:
                {
                    uint16_t r0=(instr>>9)&0x7;
                    uint16_t pc_offset=sign_extend(instr&0x1ff,9);
                    reg[r0]=mem_read(mem_read(reg[🍔_PC]+pc_offset));
                    update_flags(r0);
                }
                break;
            case 🥚_LDR:
                {
                    uint16_t r0=(instr>>9)&0x7;
                    uint16_t r1=(instr>>6)&0x7;
                    uint16_t offset=sign_extend(instr&0x3F,6);
                    reg[r0]=mem_read(reg[r1]+offset);
                    update_flags(r0);
                }
                break;
            case 🥚_LEA:
                {
                    uint16_t r0=(instr>>9)&0x7;
                    uint16_t pc_offset=sign_extend(instr&0x1ff,9);
                    reg[r0]=reg[🍔_PC]+pc_offset;
                    update_flags(r0);
                }
                break;
            case 🥚_ST:
                {
                    uint16_t r0=(instr>>9)&0x7;
                    uint16_t pc_offset=sign_extend(instr&0x1ff,9);
                    mem_write(reg[🍔_PC]+pc_offset,reg[r0]);
                }
                break;
            case 🥚_STI:
                {
                    uint16_t r0=(instr>>9)&0x7;
                    uint16_t pc_offset=sign_extend(instr&0x1ff,9);
                    mem_write(mem_read(reg[🍔_PC]+pc_offset),reg[r0]);
                }
                break;
            case 🥚_STR:
                {
                    uint16_t r0=(instr>>9)&0x7;
                    uint16_t r1=(instr>>6)&0x7;
                    uint16_t offset=sign_extend(instr&0x3F,6);
                    mem_write(reg[r1]+offset,reg[r0]);
                }
                break;
            case 🥚_TRAP:
                switch(instr&0xFF){
                    case TRAP_GETC:
                        reg[🍔_🌍]=(uint16_t)getchar();
                        break;
                    case TRAP_OUT:
                        putc((char)reg[🍔_🌍],stdout);
                        fflush(stdout);
                        break;
                    case TRAP_PUTS:
                        {
                            uint16_t* c=memory+reg[🍔_🌍];
                            while(*c){
                                putc((char)*c,stdout);
                                ++c;
                            }
                            fflush(stdout);
                        }
                        break;
                    case TRAP_IN:
                        printf("Enter a character: ");
                        char c=getchar();
                        putc(c,stdout);
                        reg[🍔_🌍]=(uint16_t)c;
                        break;
                    case TRAP_PUTSP:
                        {
                            uint16_t* c=memory+reg[🍔_🌍];
                            while (*c){
                                char char1=(*c)&0xFF;
                                putc(char1,stdout);
                                char char2=(*c)>>8;
                                if(char2)putc(char2,stdout);
                                ++c;
                            }
                            fflush(stdout);
                        }
                        break;
                    case TRAP_HALT:
                        puts("HALT");
                        fflush(stdout);
                        running=0;
                        break;
                }
                break;
            case 🥚_RES:
            case 🥚_RTI:
            default:
                abort();
                break;
        }
    }
    restore_input_buffering();
}
