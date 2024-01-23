import socket
import threading

def send_request(client_id):
    # Create a socket object
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connect to the server
    client_socket.connect(('localhost', 8080))

    # Send a message to the server
    message = f"Hello from client {client_id}"
    client_socket.send(message.encode())

    # Receive the response from the server
    response = client_socket.recv(1024).decode()
    print(f"Response from server to client {client_id}: {response}")

    # Close the socket
    client_socket.close()

# Number of concurrent clients
num_clients = 1000

# Create threads for each client
threads = []
for i in range(num_clients):
    thread = threading.Thread(target=send_request, args=(i,))
    threads.append(thread)
    thread.start()

# Wait for all threads to finish
for thread in threads:
    thread.join()

