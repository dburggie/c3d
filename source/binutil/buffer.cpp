

namespace binutil
{
	
	typedef unsigned char Byte;
	
	class Buffer
	{
		
		private:
			int size;
			int len;
			Byte * buf;
		
		public:
			Buffer();
			Buffer(int length);
			Buffer(const Buffer & buffer);
			~Buffer();
			
			
			//byte order up to implementation
			int geti(int index);
			Buffer & append(int i);
			Buffer & insert(int index, int i);
			
			//guaranteed big-endian
			int getiBE(int index);
			Buffer & appendBE(int i); 
			Buffer & insertBE(int index, int i);
			
			//guaranteed little-endian
			int getiLE(int index);
			Buffer & appendLE(int i); 
			Buffer & insertLE(int index, int i);
			
			Byte getB(int index);
			Buffer & insert(int index, Byte b)
			Buffer & append(Byte b);
			Buffer & append(int count, Byte * buffer);
			
			unsigned char getuc(int index);
			Buffer & insert(int index, unsigned char b)
			Buffer & append(unsigned char b);
			
			unsigned char * getuca(int index);
			Buffer & insert(int index, int count, unsigned char * buffer);
			Buffer & append(int count, unsigned char * buffer);
			
			char getc(int index);
			Buffer & insert(int index, char c);
			Buffer & append(char c);
			
			char * getca(int index);
			Buffer & insert(int index, int count, char * buffer);
			Buffer & append(int count, char * buffer);
			
			Buffer & insert(int index, char * string);
			Buffer & append(char * string);
			
			Buffer & insert(int index, Buffer & buffer);
			Buffer & append(Buffer & buffer);
			
			Byte operator[](int index);
			
		
	}
	
}
