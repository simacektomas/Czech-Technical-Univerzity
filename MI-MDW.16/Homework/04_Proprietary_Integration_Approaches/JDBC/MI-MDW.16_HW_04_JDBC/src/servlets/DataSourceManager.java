package servlets;

import java.io.IOException;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;

import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.sql.DataSource;

/**
 * Servlet implementation class DataSourceManager
 */
public class DataSourceManager extends HttpServlet {
	private static final long serialVersionUID = 1L;	
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DataSourceManager() {
        super();
        // TODO Auto-generated constructor stub
    }

    private Connection getConnection() {
    	Connection connection = null;
    	try {
    		InitialContext context = new InitialContext();
    		DataSource dataSource = (DataSource) context.lookup("jdbc/myDataSource");
    		connection = dataSource.getConnection();
    	}
    	catch ( NamingException e ) {
    		e.printStackTrace();
    	}
    	catch ( SQLException e ) {
    		e.printStackTrace();
    	}
    	
    	return connection;
    }
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		Connection connection = this.getConnection();
		if ( connection == null ){
			response.getWriter().append("Cannot connect to the datasource");
			return;
		}
		// Query DB
		try {
			Statement stmt = connection.createStatement();
			String query = "SELECT * FROM records";
			ResultSet rs = stmt.executeQuery(query);
			response.getWriter().append("<h1>Example of query \'" + query +  "\'</h1>\n");
			response.getWriter().append("<table>\n");
			response.getWriter().append("<tr>\n");
			response.getWriter().append("<td>ID</td>\n");
			response.getWriter().append("<td>TYPE</td>\n");
			response.getWriter().append("<td>LOCATION</td>\n");
			response.getWriter().append("<td>CAPACITY</td>\n");
			response.getWriter().append("<td>OCCUPIED</td>\n");
			response.getWriter().append("<td>TRIP</td>\n");
			response.getWriter().append("<td>PERSON</td>\n");
			response.getWriter().append("</tr>\n");
			
			ResultSetMetaData meta = rs.getMetaData();	
			final int columnCount = meta.getColumnCount();
			
			
			while(rs.next()) {
				response.getWriter().append("<tr>\n");
				for ( int i = 1; i <= columnCount; ++i ) {
					response.getWriter().append("<td>" + rs.getString(i) + "</td>\n");
				}
				response.getWriter().append("</tr>\n");
			}	
			
			response.getWriter().append("</table>");
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
				
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
