/*
Read N characters given Read4: read4(buf) reads up to 4 characters from a file into buf
and returns how many it read. Using only read4, implement read(buf, n), which reads n
characters and can be called multiple times.
*/

#include <iostream>
#include <string>
using namespace std;

class Read4 {
    
    private:
        string mockBuffer;
        int mockBufferIndex;
    
    public:
        int read(char * buf);
        Read4(){
            mockBuffer = "This is a test of ReadN given Read4";
            mockBufferIndex = 0;
        }
};

class ReadN {
    private:
        Read4 * instance;
        int remainingInBuffer;
        int bufferIndex;
        void reloadBuffer();
        char localBuffer[4];
    public:
        int read(char * buf, int n);
        ReadN(){
            instance = new Read4;
            remainingInBuffer=0;
            bufferIndex=0;
        }
};

int Read4::read(char * buf){
    int alreadyRead=0;
    for (int i = 0; ((i < 4) && (mockBufferIndex < mockBuffer.length())); i++){
        buf[i] = mockBuffer[mockBufferIndex];
        mockBufferIndex++;
        alreadyRead++;
    }
    return alreadyRead;
}

void ReadN::reloadBuffer(){
    bufferIndex = 0;
    //what is the right way to make this call
    
    remainingInBuffer = instance->read(localBuffer);
}

int ReadN::read(char * buf, int n){
    
    int alreadyRead=0;
  
    if (remainingInBuffer == 0){
        reloadBuffer();
    }
      
    //empty local buffer first
    while(alreadyRead < n && remainingInBuffer > 0){
        buf[alreadyRead] = localBuffer[bufferIndex];
        remainingInBuffer--;
        alreadyRead++;
        bufferIndex++;
        if (remainingInBuffer == 0){
            reloadBuffer();
        }
    }
    return alreadyRead;
}

int main(){
    ReadN * arbReader = new ReadN;
    char readerBuffer1[3];
    int read1 = arbReader->read(readerBuffer1,3);
    cout<<"read(3) returned {"<<string(readerBuffer1,read1)<<"}"<<endl;
    char readerBuffer2[6];
    int read2 = arbReader->read(readerBuffer2,6);
    cout<<"read(6) returned {"<<string(readerBuffer2,read2)<<"}"<<endl;
    char readerBuffer3[2];
    int read3 = arbReader->read(readerBuffer3,2);
    cout<<"read(2) returned {"<<string(readerBuffer3,read3)<<"}"<<endl;
    char readerBuffer4[25];
    int read4 = arbReader->read(readerBuffer4,25);
    cout<<"read(25) returned {"<<string(readerBuffer4,read4)<<"}"<<endl;
    return 0;
}