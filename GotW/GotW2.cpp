string FindAddr( list<Employee> l, string name )
  {
    for( list<Employee>::iterator i = l.begin();
         i != l.end();
         i++ )
    {
      if( *i == name )
      {
        return (*i).addr;
      }
    }
    return "";
  }

/* You are doing a code review. A programmer has written the following function, 
which uses unnecessary temporary objects in at least three places. */

/* How many can you identify, and how should the programmer fix them? */

/*	
	[1]:	list<Employee> l
	[2]:	string name
	[3]:	i++
	[4]:	*i == name 
	[5]:	return "";
	
*/

string FindAddr( list<Employee>& l, string& name ) const
{
	string addr;
    for( list<Employee>::iterator i = l.begin(); i != l.end(); ++i )
    {
      if( (*i).name == name )
      {
		addr = (*i).addr;
        break;
      }
    }
    return addr;
}


