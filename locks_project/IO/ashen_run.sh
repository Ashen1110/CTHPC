cd /home/ashen/locks_project/IO

./pthread_mutex-io 64 1000 100000
rm test_file.txt
./B_semaphore-io 64 1000 100000
rm test_file.txt
./mcs-io 64 1000 100000
rm test_file.txt
./pthread_spin-io 64 1000 100000
rm test_file.txt
./inuse_only-io 64 1000 100000
rm test_file.txt
./ticket-io 64 1000 100000
rm test_file.txt


