#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

namespace my
{
	template<
		class T,
		class Container = std::vector<T>,
		class Compare = std::less<typename Container::value_type>
			>
	class priority_queue
	{
		protected:
			Container c;
			Compare comp;
		public:
			// Typedefs
			using container_type = Container;
			using value_compare  = Compare;
			using value_type = typename Container::value_type;
			using size_type =  typename Container::size_type;
			using reference = typename Container::reference;
			using const_reference = typename Container::const_reference;
			

			// Ctors
			priority_queue() : priority_queue(Compare(), Container()) { }		// (1)
			explicit priority_queue( const Compare& compare)					// (2)
			: priority_queue(compare, Container()) { }
			priority_queue(const Compare& compare, const Container& cont)		// (3)
			:comp(compare), c(cont)
			{	
				 std::make_heap(c.begin(), c.end(), comp);
			}
			priority_queue(const Compare& compare, Container&& cont)			// (4)
			:comp(compare), c(std::move(cont))
			{	
				 std::make_heap(c.begin(), c.end(), comp);
			}
			priority_queue(const priority_queue& other)							// (5)
			:comp(other.comp), c(other.c) { }
			priority_queue(priority_queue&& other)								// (6)
			:comp(std::move(other.comp)), c(std::move(other.c)) { }
			
			template< class InputIt >					// DONT WORK!
			priority_queue( InputIt first, InputIt last,
                const Compare& compare = Compare() )
			:comp(compare), c(first, last)
			{
				std::make_heap(c.begin(), c.end(), comp);
			}
			template<class InputIt>												// (9)
			priority_queue( InputIt first, InputIt last,
            const Container& cont, const Compare& compare)
			:c(cont), comp(compare)
			{
				c.insert(c.end(), first, last);
				std::make_heap(c.begin(), c.end(), comp);
			}
			template<class InputIt>												// (10)
			priority_queue( InputIt first, InputIt last,
			Container&& cont, const Compare& compare)
			:c(std::move(cont)), comp(compare)
			{
				c.insert(c.end(), first, last);
				std::make_heap(c.begin(), c.end(), comp);
			}

			// Dtor
			~priority_queue() = default;

			// Operator=
			priority_queue& operator=(const priority_queue& other)
			{
				c = other.c;
				comp = other.comp;
				return *this;
			}
			priority_queue& operator=(priority_queue&& other)
			{
				c = std::move(other.c);
				comp = std::move(other.comp);
				return *this;
			}

			// Member functions
			const_reference top() const
			{
				return c.front();
			}
			bool empty() const
			{
				return c.empty();
			}

			size_type size() const
			{
				return c.size();
			}

			void push(const value_type& value)
			{
				c.push_back(value);
				std::push_heap(c.begin(), c.end(), comp);
			}
			void push(value_type&& value)
			{
				c.push_back(std::move(value));
				std::push_heap(c.begin(), c.end(), comp);
			}

			template< class... Args >
			void emplace( Args&&... args )
			{
				c.emplace_back(std::forward<Args>(args)...);
				std::push_heap(c.begin(), c.end(), comp);
			}
			
			void pop()
			{
				std::pop_heap(c.begin(), c.end(), comp);
				c.pop_back();
			}

			void swap(priority_queue& other)
			{
				using std::swap;
				swap(c, other.c);
				swap(comp, other.comp);
			}
	};

	template< typename InputIt, typename Cont = std::vector<typename std::iterator_traits<InputIt>::value_type>, typename Comp = std::less<typename std::iterator_traits<InputIt>::value_type>>
	priority_queue( InputIt, InputIt,
                const Comp& = Comp()) -> priority_queue<typename std::iterator_traits<InputIt>::value_type,
	Cont, Comp>;
	template<typename InputIt, typename Cont = std::vector<typename std::iterator_traits<InputIt>::value_type>, typename Comp = std::less<typename std::iterator_traits<InputIt>::value_type>>											// (9)
	priority_queue( InputIt , InputIt , const Cont& , const Comp&) -> priority_queue<typename std::iterator_traits<InputIt>::value_type,
	Cont, Comp>;
	template<typename InputIt, typename Cont = std::vector<typename std::iterator_traits<InputIt>::value_type>, typename Comp = std::less<typename std::iterator_traits<InputIt>::value_type>>											// (9)
	priority_queue( InputIt , InputIt ,const Cont&& , const Comp&) -> priority_queue<typename std::iterator_traits<InputIt>::value_type, Comp, Cont>;
}



#endif
