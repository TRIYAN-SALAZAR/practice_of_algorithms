function VigenèreCipher(key, abc) {
    const map_alpha = new Map();
    const key_code = [];

    const _abc = abc;
    const _key = key;

    const cycle_cipher = _key.length - 1;
    const cycle_alpha = _abc.length;

    for (let i = 1; i <= abc.length; i++) map_alpha.set(abc[i - 1], i);
    for (let i = 1; i <= key.length; i++) {
        for (let j = 0; j < abc.length; j++) {
            if (abc[j] == key[i - 1]) {
                key_code[i - 1] = j + 1;
                break;
            }
        }
    }

    const is_in_string = character => _abc.includes(character);

    this.encode = function (str) {
        let cipher_text = ``;
        let salt_key = 0;

        for (let i = 0; i < str.length; i++) {
            let character = str[i]
            let letter_salt = key_code[salt_key];
            if (is_in_string(character)) {
                let aux = map_alpha.get(character) + letter_salt;

                while ((aux > cycle_alpha + 1)) {
                    aux = (aux - cycle_alpha);
                }

                cipher_text += _abc[aux - 2];
            } else {
                cipher_text += character;
            }
            if (salt_key < cycle_cipher)
                salt_key++;
            else
                salt_key = 0;
        }

        return cipher_text;
    };

    this.decode = function (str) {
        let text = ``;
        let salt_key = 0;

        for (let i = 0; i < str.length; i++) {
            let character = str[i]
            let letter_salt = key_code[salt_key];
            if (is_in_string(character)) {
                let aux = map_alpha.get(character) - letter_salt;

                while ((aux < 0)) {
                    aux = (aux + cycle_alpha);
                }

                text += _abc[aux];
            } else {
                text += character;
            }

            if (salt_key < cycle_cipher)
                salt_key++;
            else
                salt_key = 0;
        }

        return text;
    };
}

let key, abc;
const passwords = ['pizza', 'password']
abc = "abcdefghijklmnopqrstuvwxyz";
key = passwords[1];

c = new VigenèreCipher(key, abc);
const PHRASES = [`it's a shift cipher!`, 'codewars', 'asodavwt']
const EXPETED_PHRASES = [`xt\'k o vwixl qzswej!`, 'rovwsoiv']
let str = PHRASES[0]
let expected = EXPETED_PHRASES[0]
let strEncode = c.encode(str);
console.log(strEncode);
console.log(expected);
console.log(c.decode(strEncode));