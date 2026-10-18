// Simple jQuery contact form alert
$(function(){
  $('#contactForm').on('submit', function(e){
    e.preventDefault();
    alert('Thanks, ' + $('input[name="name"]').val() + '! Your message has been sent.');
    this.reset();
  });
  $('#contactBtn').click(function(){
    window.location.href='bio-data.html#contactForm';
  });
});
