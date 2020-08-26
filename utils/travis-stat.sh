#! /bin/bash

./bin/kkmeans 3 < data/kkmeans_ex.txt > points.txt
for i in {0..2}; do
  printf "Cluster %s: %s\n" "${i}" "$(grep -c "^${i}" points.txt)"
done
