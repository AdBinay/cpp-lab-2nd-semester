# CRUD Application Documentation(c++ Labwork)

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
- `form.html`: The main HTML file where the user can add, update, and delete records. It also includes a button to view all records.
- `styles.css`: (Optional) Contains CSS styles for the HTML pages to improve aesthetics.

## Usage
- Start Your Web Server
- Ensure your Apache server is running.
- If using XAMPP, start it from the XAMPP control panel.

**Access the Application Open a web browser and go to the URL:**

- http://localhost/cgi-bin/crud.cgi
- Replace localhost with your server's IP address if accessing remotely.

## Interact with the Application

- `Add a Record`: Enter the name, address, and phone number in the provided fields and click "Add Record".
- `View All Records`: Click "View All" to see all existing records.
- `Update a Record`: Enter the existing name and new address/phone number, then click "Update Record".
- `Delete a Record`: Enter the name of the record to delete and click "Delete Record".
  
## Contributing
Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated.

- Fork the Project
- Create your Feature Branch (git checkout -b feature/AmazingFeature)
- Commit your Changes (git commit -m 'Add some AmazingFeature')
- Push to the Branch (git push origin feature/AmazingFeature)
- Open a Pull Request

## Troubleshooting

- **CGI Script Not Executing:** Ensure that the server is configured correctly for CGI scripts and that the `crud.cgi` file has execute permissions.
- **Changes Not Reflecting:** Clear the browser cache or try restarting the web server if updates to HTML or CGI scripts do not seem to take effect.

## Additional Notes

- This application is designed for educational purposes and might require additional security measures for production use, such as input validation and handling of concurrent data access.

Thank you for choosing to use the CRUD application. Should you encounter any issues or have questions, please consult this documentation or reach out for support in binayadh77@gmail.com
![image](https://github.com/user-attachments/assets/d61cca09-c358-4da1-9519-54fc68064003)

