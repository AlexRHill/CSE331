// class Node
// The nested node class for objects in our linked list.
// YOU MAY NOT MODIFY THIS CLASS!
class Node 
{
public:
  Node    *next;
  int     payload;

  Node() {next = 0;}
  Node(int t) {payload = t;  next = 0;}
  
  int Data() {return payload;}
  const int Data() const {return payload;}
};
