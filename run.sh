rm output/*
make clean
make
for i in {1..5}
do
	./tp3 < test_cases/$i.in > output/$i.out
	diff -w -s test_cases/$i.out output/$i.out >> output/compare.out
done

diff -s output/compare.out validation/expected.out