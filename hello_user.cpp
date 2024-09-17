#include <iostream>
using namespace std;

int main() {
    // Required for CGI scripting
    cout << "Content-type:text/html\n\n";
    
    // HTML with JavaScript and form
    cout << "<html>";
    cout << "<head>";
    cout << "<title>User Form</title>";
    
    // Adding JavaScript 
    cout << "<script>";
    cout << "function displayCredentials() {";
    
    // Get values from form inputs
    cout << "  var name = document.getElementById('name').value;";
    cout << "  var age = document.getElementById('age').value;";
    cout << "  var email = document.getElementById('email').value;";
    
    // Display user-entered values
    cout << "  document.getElementById('result').innerHTML = "
            "'<h2>Submitted Data</h2>' +"
            "'<p>Name: ' + name + '</p>' +"
            "'<p>Age: ' + age + '</p>' +"
            "'<p>Email: ' + email + '</p>';";
    
    cout << "  return false;";  // Prevent form submission
    cout << "}";
    cout << "</script>";
    
    cout << "</head>";
    cout << "<body>";
    
    // Displaying the form
    cout << "<h1>Enter your details</h1>";
    cout << "<form onsubmit='return displayCredentials()'>"; // JavaScript handles the form submission
    cout << "Name: <input type='text' id='name' name='name'><br>";
    cout << "Age: <input type='number' id='age' name='age'><br>";
    cout << "Email: <input type='email' id='email' name='email'><br>";
    cout << "<input type='submit' value='Submit'>";
    cout << "</form>";
    
    // Placeholder to display result
    cout << "<div id='result'></div>";
    
    cout << "</body>";
    cout << "</html>";
    
    return 0;
}

