path=$1
ext=$2
backup=$3
backupzip=$4

mkdir -p $backup

files=`find $path -name "*$ext"`

length=`expr length $path`

#echo "Длина пути до папки: $length"

for i in $files
do
	mkdir -p `dirname $backup/${i:length}`
	cp $i "$backup/${i:length}"
done

tar -czf $backupzip $backup
echo done
