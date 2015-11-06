//#include <stdio.h>
//#include <assert.h>
//#include <iostream>
//
//class CString {
//public:
//	CString();
//	CString( const char* str );
//	const CString& operator = ( const CString& other );
//	CString( const CString& other );
//	void Append ( const char* str );
//	void operator += ( const char* str );
//	void AppendCStr ( const CString& str );
//	char operator [] ( int i ) const;
//	void Print ();
//	int Length ();
//	CString Mid ( int first, int n ) const;
//	CString Left ( int n );
//	CString Right ( int n );
//	friend std::ostream& operator << (std::ostream& out , const CString& str);
//	CString ReverseWords (); 
//private:
//	char* string;
//	int length;
//};
//
//CString::CString() {
//	string = new char [1];
//	length = 0;
//	string[0] = '\0';
//};
//
//CString::CString( const char* str ) {
//	length = strlen( str );  
//	string = new char [length + 1];
//	strcpy( string, str );
//};
//
//const CString& CString::operator = ( const CString& other ) {
//	char* temp = new char[other.length + 1];
//	strcpy( temp, other.string );
//	delete[] this->string;
//	string = temp;
//	length = other.length;
//	return other;
//};
//
//CString::CString( const CString& other ) {
//	this -> length = other.length;
//	this -> string = new char [other.length + 1];
//	strcpy ( this -> string, other.string );
//};
//
//void CString::Append ( const char* str ) { 
//	assert( str != NULL );
//	char* temp = new char[strlen( str ) + this -> length + 1];
//	for ( int i = 0; i < ( strlen( str ) + this -> length ) ; ++i ) {
//		if ( i < this -> length ) {
//			temp[i] = this -> string[i];
//		} else {
//			temp[i] = str[i - this -> length];
//		}
//	}	
//	temp[strlen( str ) + this -> length] = '\0';
//	delete[] string;
//	this -> string = temp;
//	this -> length += strlen( str );
//};
//
//void CString::operator += ( const char* str ) {
//	Append( str );
//};
//	
//void CString::AppendCStr ( const CString& str ) {
//	this -> Append( str.string );
//};
//
//char CString::operator [] ( int i ) const {
//	assert ( i >= 0 && i < this -> length );
//	return string[i];
//};
//
//void CString::Print () {
//	printf( "%s", this -> string );
//};
//
//int CString::Length () {
//	return this -> length;
//};
//CString CString::Mid ( int first, int n ) const {
//	assert( first >= 0 && first < this -> length && first + n <= this -> length );
//	CString temp;
//	char * TempString = new char[n+1];
//	for ( int i = first; i < first + n; ++i ) {
//		TempString[i - first] = this -> string[i];
//	}
//	TempString[n] = '\0';
//	temp += TempString ;
//	delete[] TempString;
//	return temp;
//};
//
//CString CString::Left ( int n ) {
//	assert ( n < this -> length );
//	return this -> Mid( 0, n );
//}
//
//CString CString::Right ( int n ) {
//	assert ( n < this -> length );
//	CString temp;
//	delete[] temp.string;
//	temp.string = new char[n+1];
//	strncpy( temp.string, &( this -> string)[this -> length - n], n + 1 );
//	temp.length = n;
//	return temp;
//}
//
//std::ostream& operator << ( std::ostream& out , const CString& str ) {
//	return out << str.string;
//}
//
//CString CString::ReverseWords () {
//	CString temp;
//	int PeremLength = 0;
//	for ( int i = this -> length - 1; i >= 0; --i ) {
//		PeremLength++;
//		if ( ( this -> string[i] == ' ' ) ) {
//		temp.AppendCStr( this -> Mid( i + 1, PeremLength - 1 ) );
//		temp.Append( " " );
//		PeremLength = 0;
//		} else { 
//			if ( i == 0 ) {
//				temp.AppendCStr( this -> Mid( i, PeremLength ) );
//				PeremLength = 0;
//			}
//		}
//	}
//	return temp;
//}
//
////int main()
////{
////	CString str = "111 222 333 4 17";
////	CString a = "venera";
////	CString b = "Mars";
////	str.ReverseWords();
////	str += "abrakadabra";
////	std::cout << str;
////	b = str = a;
////	b.Print();
////}
//
//
