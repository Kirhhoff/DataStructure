void Assert(bool,const char*);
template<class E>
class Stack{
	
	public:
		Stack(){}
		virtual ~Stack(){}
	
	public:
		virtual E pop()=0;
		virtual void push(const E&)=0;
		virtual const E& topValue()const=0;
		virtual int length()const=0;
		virtual void clear()=0;
	

};
