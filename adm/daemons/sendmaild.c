// sendmail.c 

#include <socket_err.h>
#include <net/config.h>
#include <net/daemons.h>
#include <net/dns.h>
#include <net/macros.h>
#include <net/services.h>
#include <net/socket.h>

// prototypes
string send_mail(string rcpt, mixed data);
void read_callback(int fd, mixed msg);
void close_callback(int fd);
void write_callback(int fd);

void log(string msg);

// global vars 
// pls change these to ur own smtp server address
string smtp_domain = "public3.bta.net.cn";
string smtp_ip = "202.96.0.193 25";

string sender = "lanxin@netease.com";
string receiver;
mixed message;

string send_mail(string rcpt, mixed data)
{
	int id, err;
	string err_msg, tmp1, tmp2;

	if(!rcpt) return "MissingAddr";

	if(sscanf(rcpt, "%s@%s", tmp1, tmp2) != 2)
		return "InvalidAddr";

	if(tmp1 == "" || tmp2 == "")
		return "InvalidAddr";

	err_msg = "InternalError!";

	id = socket_create(STREAM, "read_callback", "close_callback");
	if(id < 0)
	{
		log("Send_mail: socket_creation: " + socket_error(id) + "\n");
		return err_msg;
	}

	err = socket_connect(id, smtp_ip, "read_callback", "write_callback");
	if(err <= 0)
        {
                log("Send_mail: socket_connect: " + socket_error(err) + "\n");
		return err_msg;
	}

	receiver = rcpt;
	message = data;
}

void read_callback(int fd, mixed msg)
{
	log("Read_callback: " + msg + "\n");
}

void write_callback(int fd)
{
	int err;

	err = socket_write(fd, "HELO " + smtp_domain + "\n" +
			"MAIL FROM: <" + sender + ">\n" + 
			"RCPT TO: <" + receiver + ">\n" +
			"DATA\n" + message + "\n.\n" +
			"QUIT\n");
	if(err <= 0)
		log("Write_callback: socket_write: " + socket_error(err) + "\n");

	socket_close(fd);
}
			
void log(string msg)
{
	log_file("sendmail", msg);
}
