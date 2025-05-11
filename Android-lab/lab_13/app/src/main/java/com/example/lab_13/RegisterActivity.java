package com.example.lab_13;

import android.annotation.SuppressLint;
import android.app.DatePickerDialog;
import android.text.Editable;
import android.text.TextWatcher;

import com.example.lab_13.databinding.ActivityRegisterBinding;
import com.example.lab_13.models.User;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Calendar;

public class RegisterActivity extends AuthBaseActivity {
    private ActivityRegisterBinding binding;

    @Override
    protected void getLayoutResource() {
        binding = ActivityRegisterBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
    }

    @Override
    protected void initViews() {
        emailEt = binding.emailEt;
        passwordEt = binding.passwordEt;
        usernameEt = binding.usernameEt;
        phoneEt = binding.phoneEt;
        birthdayEt = binding.birthdayEt;
        confirmPasswordEt = binding.confirmPasswordEt;
        progressBar = binding.progressBar;
        actionBtn = binding.signUpBtn;
        backBtn = binding.backBtn;
        rememberMeCb = binding.rememberMeCb;
    }

    @Override
    protected void setupListeners() {
        backBtn.setOnClickListener(v -> finish());
        actionBtn.setOnClickListener(v -> performAuthAction());

        phoneEt.addTextChangedListener(new PhoneNumberTextWatcher(phoneEt));
        birthdayEt.setOnClickListener(v -> showDatePicker());
        birthdayEt.addTextChangedListener(new BirthdayTextWatcher());
    }

    private void showDatePicker() {
        Calendar calendar = Calendar.getInstance();
        new DatePickerDialog(this, (view, year, month, day) -> {
            @SuppressLint("DefaultLocale") String date = String.format("%02d.%02d.%d", day, month + 1, year);
            birthdayEt.setText(date);
        }, calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH), calendar.get(Calendar.DAY_OF_MONTH)).show();
    }

    protected void performAuthAction() {
        String username = usernameEt.getText().toString().trim();
        String email = emailEt.getText().toString().trim();
        String password = passwordEt.getText().toString().trim();
        String phone = phoneEt.getText().toString().trim();
        String birthday = birthdayEt.getText().toString().trim();
        String confirmPassword = confirmPasswordEt.getText().toString().trim();

        if (!validateUsername(username) ||
                !validateEmail(email) ||
                !validatePassword(password) ||
                !validatePhone(phone) ||
                !validateBirthday(birthday) ||
                !validatePasswordConfirmation(password, confirmPassword)) {
            return;
        }

        setLoadingState(true);

        String hashedPassword = hashPassword(password);
        User user = new User(username, email, hashedPassword, phone, birthday);

        // Register user
    }

    private String hashPassword(String password) {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] hash = digest.digest(password.getBytes());
            StringBuilder hexString = new StringBuilder();
            for (byte b : hash) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            return password;
        }
    }

    private class BirthdayTextWatcher implements TextWatcher {
        private String current = "";

        @Override public void beforeTextChanged(CharSequence s, int start, int count, int after) {}
        @Override public void onTextChanged(CharSequence s, int start, int before, int count) {}

        @Override
        public void afterTextChanged(Editable s) {
            if (s.toString().equals(current)) return;

            String clean = s.toString().replaceAll("\\D", "");
            if (clean.length() > 8) clean = clean.substring(0, 8);

            StringBuilder formatted = new StringBuilder();
            int len = clean.length();
            for (int i = 0; i < len; i++) {
                formatted.append(clean.charAt(i));
                if ((i == 1 || i == 3) && i != len - 1) formatted.append(".");
            }

            current = formatted.toString();
            birthdayEt.removeTextChangedListener(this);
            birthdayEt.setText(current);
            birthdayEt.setSelection(current.length());
            birthdayEt.addTextChangedListener(this);
        }
    }
}