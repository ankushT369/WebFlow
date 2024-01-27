import requests
import threading

def send_request(method, url, data=None):
    try:
        if method == 'GET':
            response = requests.get(url)
        elif method == 'POST':
            response = requests.post(url, data=data)
        elif method == 'PUT':
            response = requests.put(url, data=data)
        elif method == 'DELETE':
            response = requests.delete(url)
        else:
            print(f"Invalid method: {method}")
            return

        print(f"Response from {method} request to {url}: {response.text}")
    except Exception as e:
        print(f"Error in {method} request to {url}: {e}")

# URL of the server
server_url = 'http://localhost:8080/'

# Create threads for each request
threads = []

# Concurrent GET request
thread_get = threading.Thread(target=send_request, args=('GET', server_url))
threads.append(thread_get)

# Concurrent POST request with data
data_for_post = {'key': 'value'}
thread_post = threading.Thread(target=send_request, args=('POST', server_url, data_for_post))
threads.append(thread_post)

# Concurrent PUT request with data
data_for_put = {'key': 'updated_value'}
thread_put = threading.Thread(target=send_request, args=('PUT', server_url, data_for_put))
threads.append(thread_put)

# Concurrent DELETE request
thread_delete = threading.Thread(target=send_request, args=('DELETE', server_url))
threads.append(thread_delete)

# Start all threads
for thread in threads:
    thread.start()

# Wait for all threads to finish
for thread in threads:
    thread.join()

