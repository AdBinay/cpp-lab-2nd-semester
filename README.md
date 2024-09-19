# CRUD Application Documentation

Welcome to the README documentation for the CRUD (Create, Read, Update, Delete) application. This application is designed to manage records through a simple web interface using HTML forms and a CGI script backend written in C++. Below you'll find setup instructions, usage details, and a brief overview of the system architecture.

## System Requirements

- Web Server with CGI support (e.g., Apache with `mod_cgi` enabled)
- C++ compiler (e.g., g++, clang++)
- Access to edit and execute CGI scripts

## Installation

1. **Web Server Setup:**
   Ensure your web server is set up to handle CGI scripts. This often involves enabling certain modules and configuring the server to execute files in a specific `cgi-bin` directory.

2. **Compiling the Script:**
   Navigate to the directory containing the `crud.cpp` file and compile it using a C++ compiler:
   ```bash
   g++ -o crud.cgi crud.cpp
   ```
   Move the resulting `crud.cgi` executable to your server's `cgi-bin` directory.

3. **Setting Permissions:**
   Set the appropriate execute permissions on the `crud.cgi` file:
   ```bash
   chmod +x crud.cgi
   ```

4. **Configure HTML Files:**
   Place the provided HTML files in your server's public directory to be served as the front end for the application.

## Usage

The CRUD application includes several functionalities, each accessible through simple HTML forms:

- **Adding a Record:** Fill in the name, address, and phone number in the respective fields and submit.
- **Viewing All Records:** Click the "View All" button to display all existing records in a tabulated format.
- **Updating a Record:** Enter the name of the record you wish to update along with the new address and phone number.
- **Deleting a Record:** Enter the name of the record you wish to delete and submit the form.

## File Structure

- `crud.cpp`: Contains the logic for handling CRUD operations. It reads from and writes to a `records.txt` file which stores the data.
- `index.html`: The main HTML file where the user can add, update, and delete records. It also includes a button to view all records.
- `styles.css`: (Optional) Contains CSS styles for the HTML pages to improve aesthetics.

## Troubleshooting

- **CGI Script Not Executing:** Ensure that the server is configured correctly for CGI scripts and that the `crud.cgi` file has execute permissions.
- **Changes Not Reflecting:** Clear the browser cache or try restarting the web server if updates to HTML or CGI scripts do not seem to take effect.

## Additional Notes

- This application is designed for educational purposes and might require additional security measures for production use, such as input validation and handling of concurrent data access.

Thank you for choosing to use the CRUD application. Should you encounter any issues or have questions, please consult this documentation or reach out for support.
![image](https://github.com/user-attachments/assets/d61cca09-c358-4da1-9519-54fc68064003)

