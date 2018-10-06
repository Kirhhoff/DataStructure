
template<class E>
class List{
	protected:
	class Link{
		private:
		static Link* freeList;

		public:
		E element;
		Link* next;
	
		public:		
		Link(const E& newElement):element(newElement){}
		Link(){}
		~Link(){}

		public:
		void* operator new(size_t){
			if(!freeList)
				return ::new Link;
			Link* tmp=freeList;
			freeList=freeList->next;
			return tmp;
		}

		void operator delete(void* ptr){
			((Link*)ptr)->next=freeList;
			freeList=(Link*)ptr;
		}
	};

	public:
	List(){}
	virtual ~List(){}
};

template<class E>
typename List<E>::Link* List<E>::Link::freeList=0;




