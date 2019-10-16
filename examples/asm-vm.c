//virtual machine client in emojiC and emojiASM
#include <🤑.h>
#include <🤐.h>
#include <🤥.h>
#include <💀.h>
#include <👂/🤷‍♀️.h>
#include <👂/👨‍🚒.h>
#include <👂/💆.h>
#include <👂/⛷.h>
#include <🐫.h>
#include <🐼.h>
#include <🌿.h>
🧀{
    🍔_🌍=0,
    🍔_🚊,
    🍔_🎄,
    🍔_🔒,
    🍔_🛁,
    🍔_🍎,
    🍔_🐔,
    🍔_🙇,
    🍔_🙅,
    🍔_🎅,
    🍔_👶
}🧀{
    🥚_🕋=0,
    🥚_🚚,
    🥚_🤵,
    🥚_🔰,
    🥚_👄,
    🥚_⚾,
    🥚_👩‍💻,
    🥚_👊,
    🥚_🐀,
    🥚_🌒,
    🥚_🚲,
    🥚_💊,
    🥚_👁️‍🗨️,
    🥚_✨,
    🥚_💅,
    🥚_👃
}🧀{
    🍴_💯=1<<0,
    🍴_💛=1<<1,
    🍴_🙊=1<<2,
}🧀{
    😻_😹=0xFE00,
    😻_👺=0xFE02
}🧀{
    👃_🙃=0x20,
    👃_😶=0x21,
    👃_🥳=0x22,
    👃_😡=0x23,
    👃_😑=0x24,
    👃_🥶=0x25
}
💤 🤩[😈];
💤 💩[🍔_👶];
💤 😜(💤 😆,💙 😀){
    🥺((😆>>(😀-1))&1){
        😆 |= (0xFFFF<<😀);
    }
    return(😆);
}
💤 🎱(💤 😆){
    return(😆<<8)|(😆>>8);
}
🤡 update_flags(💤 🤓){
    🥺(💩[🤓]==0){
        💩[🍔_🎅]=🍴_💛;
    }🎭 🥺(💩[🤓]>>15){
        💩[🍔_🎅]=🍴_🙊;
    }🎭{
        💩[🍔_🎅]=🍴_💯;
    }
}
🤡 read_image_file(FILE* file){
    💤 origin;
    fread(&origin,sizeof(origin),1,file);
    origin=🎱(origin);
    💤 max_read=😈-origin;
    💤* p=🤩+origin;
    size_t read=fread(p,sizeof(💤),max_read,file);
    while(read-- >0){
        *p=🎱(*p);
        ++p;
    }
}
💙 read_image(const char* image_path){
    FILE* file=fopen(image_path,"rb");
    🥺(!file){return(0);};
    read_image_file(file);
    fclose(file);
    return(1);
}
💤 check_key(){
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO,&readfds);
    struct timeval timeout;
    timeout.tv_sec=0;
    timeout.tv_usec=0;
    return select(1,&readfds,NULL,NULL,&timeout)!=0;
}
🤡 mem_write(💤 address,💤 val){
    🤩[address]=val;
}
uint16_t mem_read(💤 address){
    🥺(address==😻_😹){
        🥺(check_key()){
            🤩[😻_😹]=(1<<15);
            🤩[😻_👺]=getchar();
        }🎭{
            🤩[😻_😹]=0;
        }
    }
    return 🤩[address];
}
struct termios original_tio;
🤡 disable_input_buffering(){
    tcgetattr(STDIN_FILENO,&original_tio);
    struct termios new_tio=original_tio;
    new_tio.c_lflag&=~ICANON&~ECHO;
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
}
🤡 restore_input_buffering(){
    tcsetattr(STDIN_FILENO,TCSANOW,&original_tio);
}
🤡 handle_interrupt(💙 signal){
    restore_input_buffering();
    printf("\n");
    exit(-2);
}
💙 main(💙 argc,const char* argv[]){
    🥺(argc<2){
        printf("vomit lmao [image-file1] ...\n");
        exit(2);
    }
    for(💙 j=1;j<argc;++j){
        🥺(!read_image(argv[j])){
            printf("your iso failed, retard.: %s\n",argv[j]);
            exit(1);
        }
    }
    signal(SIGINT,handle_interrupt);
    disable_input_buffering();
    🧀{🙅_START=0x3000};
    💩[🍔_🙅]=🙅_START;
    💙 running=1;
    while(running){
        💤 instr=mem_read(💩[🍔_🙅]++);
        💤 op=instr>>12;
        switch(op){
            case OP_🚚:{
                    💤 r0=(instr>>9)&0x7;
                    💤 r1=(instr>>6)&0x7;
                    💤 imm_flag=(instr>>5)&0x1;
                    🥺(imm_flag){
                        💤 imm5=😜(instr&0x1F,5);
                        💩[r0]=💩[r1]+imm5;
                    }🎭{
                        💤 r2=instr&0x7;
                        💩[r0]=💩[r1]+💩[r2];
                    }
                    update_flags(r0);
                }
                break;
            case 🥚_⚾:{
                    💤 r0=(instr>>9)&0x7;
                    💤 r1=(instr>>6)&0x7;
                    💤 imm_flag=(instr>>5)&0x1;
                    🥺(imm_flag){
                        💤 imm5=😜(instr&0x1F,5);
                        💩[r0]=💩[r1]&imm5;
                    }🎭{
                        💤 r2=instr&0x7;
                        💩[r0]=💩[r1]&💩[r2];
                    }
                    update_flags(r0);
                }
                break;
            case 🥚_🌒:
                {
                    💤 r0=(instr>>9)&0x7;
                    💤 r1=(instr>>6)&0x7;
                    💩[r0]=~💩[r1];
                    update_flags(r0);
                }
                break;
            case 🥚_🕋:{
                    💤 pc_offset=😜((instr)&0x1ff,9);
                    💤 cond_flag=(instr>>9)&0x7;
                    🥺(cond_flag&💩[🍔_🎅]){
                        💩[🍔_🙅]+=pc_offset;
                    }
                }
                break;
            case 🥚_👁️‍🗨️:
                {
                    💤 r1=(instr>>6)&0x7;
                    💩[🍔_🙅]=💩[r1];
                }
                break;
            case 🥚_👄:
                {
                    💤 r1=(instr>>6)&0x7;
                    💤 long_pc_offset=😜(instr&0x7ff,11);
                    💤 long_flag=(instr>>11)&1;
                    💩[🍔_🙇]=💩[🍔_🙅];
                    🥺(long_flag){
                        💩[🍔_🙅]+=long_pc_offset;
                    }
                    🎭{
                        💩[🍔_🙅]=💩[r1];
                    }
                    break;
                }
                break;
            case 🥚_🤵:
                {
                    💤 r0=(instr>>9)&0x7;
                    💤 pc_offset=😜(instr&0x1ff,9);
                    💩[r0]=mem_read(💩[🍔_🙅]+pc_offset);
                    update_flags(r0);
                }
                break;
            case 🥚_🚲:
                {
                    💤 r0=(instr>>9)&0x7;
                    💤 pc_offset=😜(instr&0x1ff,9);
                    💩[r0]=mem_read(mem_read(💩[🍔_🙅]+pc_offset));
                    update_flags(r0);
                }
                break;
            case 🥚_👩‍💻:
                {
                    💤 r0=(instr>>9)&0x7;
                    💤 r1=(instr>>6)&0x7;
                    💤 offset=😜(instr&0x3F,6);
                    💩[r0]=mem_read(💩[r1]+offset);
                    update_flags(r0);
                }
                break;
            case 🥚_💅:
                {
                    💤 r0=(instr>>9)&0x7;
                    💤 pc_offset=😜(instr&0x1ff,9);
                    💩[r0]=💩[🍔_🙅]+pc_offset;
                    update_flags(r0);
                }
                break;
            case 🥚_🔰:
                {
                    💤 r0=(instr>>9)&0x7;
                    💤 pc_offset=😜(instr&0x1ff,9);
                    mem_write(💩[🍔_🙅]+pc_offset,💩[r0]);
                }
                break;
            case 🥚_💊:
                {
                    💤 r0=(instr>>9)&0x7;
                    💤 pc_offset=😜(instr&0x1ff,9);
                    mem_write(mem_read(💩[🍔_🙅]+pc_offset),💩[r0]);
                }
                break;
            case 🥚_👊:
                {
                    💤 r0=(instr>>9)&0x7;
                    💤 r1=(instr>>6)&0x7;
                    💤 offset=😜(instr&0x3F,6);
                    mem_write(💩[r1]+offset,💩[r0]);
                }
                break;
            case 🥚_👃:
                switch(instr&0xFF){
                    case 👃_🙃:
                        💩[🍔_🌍]=(💤)getchar();
                        break;
                    case 👃_😶:
                        putc((char)💩[🍔_🌍],stdout);
                        fflush(stdout);
                        break;
                    case 👃_🥳:
                        {
                            💤* c=🤩+💩[🍔_🌍];
                            while(*c){
                                putc((char)*c,stdout);
                                ++c;
                            }
                            fflush(stdout);
                        }
                        break;
                    case 👃_😡:
                        printf("Enter a character: ");
                        char c=getchar();
                        putc(c,stdout);
                        💩[🍔_🌍]=(💤)c;
                        break;
                    case 👃_😑:
                        {
                            💤* c=🤩+💩[🍔_🌍];
                            while (*c){
                                char char1=(*c)&0xFF;
                                putc(char1,stdout);
                                char char2=(*c)>>8;
                                🥺(char2)putc(char2,stdout);
                                ++c;
                            }
                            fflush(stdout);
                        }
                        break;
                    case 👃_🥶:
                        puts("🥶");
                        fflush(stdout);
                        running=0;
                        break;
                }
                break;
            case 🥚_✨:
            case 🥚_🐀:
            default:
                abort();
                break;
        }
    }
    restore_input_buffering();
}
//better do this in other languages
