//v2
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

/*How many of the pitfalls in GotW #2 could have been avoided in the first place if the programmer had just used 
a standard-library algorithm instead of handcrafting his own loop? 
(Note: as before, don't change the semantics of the function even though they could be improved.) */

//v3
string FindAddr( list<Employee>& l, string& name ) const
{
	string addr;
    for( list<Employee>::const_iterator i = l.begin(); i != l.end(); ++i )
    {
      if( (*i).name == name )
      {
		addr = (*i).addr;
        break;
      }
    }
    return addr;
}

//v4-last
string FindAddr( list<Employee>& l, string& name ) const
{
	string addr;
    for( auto i = l.cbegin(); i != l.cend(); ++i ) //C++11
    {
      if( (*i).name == name )
      {
		addr = (*i).addr;
        break;
      }
    }
    return addr;
}