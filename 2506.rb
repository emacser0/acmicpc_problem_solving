s=0;c=1;n=gets.to_i;l=gets.split.map(&:to_i);l.each{|x|(s+=c;c+=1) if x==1;c=1 if x==0}
puts s
