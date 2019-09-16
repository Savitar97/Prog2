/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package company.nemesis.servlets;

import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author nemesis
 */
@WebServlet(name = "nemesis", urlPatterns = {"/nemesis"})
public class nemesis extends HttpServlet {

   @Override
public void doGet(HttpServletRequest request, HttpServletResponse response)
throws ServletException, IOException { 
   
String bemenet = request.getParameter("text");
byte[] bytes = bemenet.getBytes();
LZWBinFa binFa = new LZWBinFa();
java.io.PrintWriter kiFile =new java.io.PrintWriter(new java.io.BufferedWriter(new java.io.FileWriter("output.txt")));

boolean kommentben = false;
for(int j = 0; j < bytes.length; ++j) 
{
   if (bytes[j] == 0x3e)
   {
      kommentben = true;
      continue;
   }
   if (bytes[j] == 0x0a)
   {
      kommentben = false;
      continue;
   }
   if (kommentben) 
   {
      continue;
   }
   if (bytes[j] == 0x4e)
   {
      continue;
   }
   for (int i = 0; i < 8; ++i) 
   {
      if ((bytes[j] & 0x80) != 0)
      {
         binFa.egyBitFeldolg('1');
      }
      else
      {
         binFa.egyBitFeldolg('0');
      }
      bytes[j] <<= 1;
   }
}
   
   
binFa.kiir(kiFile);
kiFile.println("depth = " + binFa.getMelyseg());
kiFile.println("mean = " + binFa.getAtlag());
kiFile.println("var = " + binFa.getSzoras());
kiFile.close();
File file = new File("output.txt");
FileInputStream finstream = new FileInputStream(file);
   
   
// Set response content type
response.setContentType("text/html");
PrintWriter out = response.getWriter();
out.println("<html>");
out.println("<head><title>BinfaServlet</title></head>");
out.println("<body>");
out.println("<h1>Binfa</h1>");
try(BufferedReader br = new BufferedReader(new InputStreamReader(finstream))) 
{
   for(String line; (line = br.readLine()) != null; )
   {
      out.println("<p>" + line + "</p>");
   }
}
out.println("</body></html>");
}
}
