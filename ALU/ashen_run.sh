cd /home/ashen/locks_project/ALU


#./pthread_spin-alu 64 160000
#./pthread_spin-alu 64 120000
#./pthread_spin-alu 64 80000
#./pthread_spin-alu 64 40000
#./pthread_spin-alu 64 20000
#./pthread_spin-alu 64 10000
#./pthread_spin-alu 64 5000
#./pthread_spin-alu 64 2500
#./pthread_spin-alu 64 1000

#cp result.txt plock_ncs.txt
#rm result.txt

#./ticket-alu 64 160000
#./ticket-alu 64 120000
#./ticket-alu 64 80000
#./ticket-alu 64 40000
#./ticket-alu 64 20000
#./ticket-alu 64 10000
#./ticket-alu 64 5000
#./ticket-alu 64 2500
#./ticket-alu 64 1000

#cp result.txt ticket_ncs.txt
#rm result.txt

./inuse_only-alu 64 160000
./inuse_only-alu 64 120000
./inuse_only-alu 64 80000
./inuse_only-alu 64 40000
./inuse_only-alu 64 20000
./inuse_only-alu 64 10000
./inuse_only-alu 64 5000
./inuse_only-alu 64 2500
./inuse_only-alu 64 1000

cp result.txt inuse_ncs.txt
# result.txt

#./mcs-alu 64 160000
#./mcs-alu 64 120000
#./mcs-alu 64 80000
#./mcs-alu 64 40000
#./mcs-alu 64 20000
#./mcs-alu 64 10000
#./mcs-alu 64 5000
#./mcs-alu 64 2500
#./mcs-alu 64 1000

#cp result.txt mcs_ncs.txt
#rm result.txt

#./pthread_mutex-alu 64 160000
#./pthread_mutex-alu 64 120000
#./pthread_mutex-alu 64 80000
#./pthread_mutex-alu 64 40000
#./pthread_mutex-alu 64 20000
#./pthread_mutex-alu 64 10000
#./pthread_mutex-alu 64 5000
#./pthread_mutex-alu 64 2500
#./pthread_mutex-alu 64 1000

#cp result.txt mutex_ncs.txt
#rm result.txt

#./B_semaphore-alu 64 160000
#./B_semaphore-alu 64 120000
#./B_semaphore-alu 64 80000
#./B_semaphore-alu 64 40000
#./B_semaphore-alu 64 20000
#./B_semaphore-alu 64 10000
#./B_semaphore-alu 64 5000
#./B_semaphore-alu 64 2500
#./B_semaphore-alu 64 1000
#cp result.txt semaphore_ncs.txt
#rm result.txt


#./inuse_only-alu 128 1000
#cp result.txt inuse_fair.txt
#rm result.txt
#./mcs-alu 128 1000
#cp result.txt mcs_fair.txt
#rm result.txt
#./pthread_mutex-alu 128 1000
#cp result.txt mutex_fair.txt
#rm result.txt
#./pthread_spin-alu 128 1000
#cp result.txt plock_fair.txt
#rm result.txt
#./ticket-alu 128 1000
#cp result.txt ticket_fair.txt
#rm result.txt
#./B_semaphore-alu 128 1000
#cp result.txt semaphore_fair.txt
#rm result.txt
