% Naloga 1_1

filename = "DN1\naloga1_1.txt";
delimiter = ";";
headerlines = 2;
podatki_1 = importdata(filename,delimiter,headerlines);

t = podatki_1.data;

% Naloga 1_2


podatki_2 = fopen("DN1\naloga1_2.txt");

vrsta_1 = fgetl(podatki_2);
vrstica_1 = split(vrsta_1,":");
n_vrstic = str2double(vrstica_1(2));

P = zeros(n_vrstic,1);

for i=1:n_vrstic
    vrsticai = fgetl(podatki_2);
    vrednost = str2double(vrsticai);
    P(i) = vrednost;

end
fclose(podatki_2);

plot(t, P,'red', LineWidth=2);
xlabel('t [s]');                
ylabel('P [W]');                
title('graf P(t)');

% Naloga 1_3


P_sestevek = P(1) + P(size(P,1));
n_sestevek = (size(P,1)-1);


for i=2 : n_sestevek
    P_sestevek = P_sestevek + 2*P(i);
end



int_lasten = (0.01010101010101/2) * P_sestevek
int_trapz = trapz(t,P)

