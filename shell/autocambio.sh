for a in ` find  -name "*" -print`; do
sed -i 's/'$1'/'$2'/g' $a
done
